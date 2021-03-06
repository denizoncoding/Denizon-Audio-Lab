/*
 * Copyright 2019 Deniz A. ATLIHAN
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.denizoncoding.denizonaudiolab;

import android.content.Context;
import android.media.AudioManager;
import android.os.Build;
import android.os.Bundle;
import android.view.View;
import android.widget.ListView;
import android.widget.Toast;
import android.widget.ToggleButton;

import androidx.appcompat.app.AppCompatActivity;

import com.denizoncoding.denizonaudiolab.list.EffectsAdapter;
import com.denizoncoding.denizonaudiolab.synth.Effect;
import com.denizoncoding.denizonaudiolab.synth.Synthesizer;
import com.denizoncoding.denizonaudiolab.wrapper.ObjectGenerator;
import com.denizoncoding.denizonaudiolab.wrapper.Wrapper;

import java.util.List;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    ToggleButton onOffButton;
    Wrapper wrapper;

    private Synthesizer synth;

    static {

        System.loadLibrary("native-lib");
    }


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        onOffButton = findViewById(R.id.toggleButton);
        onOffButton.setOnClickListener(this);


        if (!initializeEngine()) {

            Toast.makeText(this, "Engine Failed!", Toast.LENGTH_LONG).show();
            finish();

            return;
        }

        wrapper = new Wrapper();
        ObjectGenerator objectGenerator = new ObjectGenerator(wrapper);

        List<Effect> allEffects = objectGenerator.getAll();

        final ListView listView = (ListView) findViewById(R.id.listView);
        EffectsAdapter adapter = new EffectsAdapter(this, allEffects);
        listView.setAdapter(adapter);

    }

    @Override
    protected void onResume() {

        super.onResume();
//        synth.start();
    }

    @Override
    protected void onPause() {

        synth.pause();
        onOffButton.setChecked(false);
        super.onPause();

    }

    @Override
    protected void onStop() {

        super.onStop();
    }

    @Override
    protected void onDestroy() {

        synth.destroy();
        super.onDestroy();
    }


    @Override
    public void onClick(View v) {

        switch (v.getId()) {
            case R.id.toggleButton:

                if (onOffButton.isChecked()) {

                    synth.start();
                    synth.setSynthesis(true);
//                    infoText.setText("on");

                } else {

                    synth.setSynthesis(false);
//                    infoText.setText("off");
                    synth.pause();

                }

                break;
        }
    }

    private boolean initializeEngine() {

        Integer sampleRate = 44100;

        try {

            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.JELLY_BEAN_MR1) {

                AudioManager am = (AudioManager) getSystemService(Context.AUDIO_SERVICE);

                sampleRate = Integer.parseInt(am.getProperty(AudioManager.PROPERTY_OUTPUT_SAMPLE_RATE));

                if (sampleRate == null || sampleRate <= 0) {

                    return false;
                }
            }

        } catch (Exception e) {

            e.printStackTrace();

            return false;
        }

        synth = new Synthesizer();

        return synth.initialize(sampleRate, 440);
    }

}
