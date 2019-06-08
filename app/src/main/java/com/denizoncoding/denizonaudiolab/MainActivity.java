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
import android.support.annotation.RequiresApi;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.CompoundButton;
import android.widget.ListView;
import android.widget.RadioButton;
import android.widget.SeekBar;
import android.widget.Toast;
import android.widget.ToggleButton;

import com.denizoncoding.denizonaudiolab.structure.DenizonEffect;
import com.denizoncoding.denizonaudiolab.structure.DenizonEffectParameter;
import com.denizoncoding.denizonaudiolab.synth.Synthesizer;
import com.denizoncoding.denizonaudiolab.synth.WaveType;
import com.denizoncoding.denizonaudiolab.ui.EffectListArrayAdapter;

import java.util.LinkedList;

public class MainActivity extends AppCompatActivity implements View.OnClickListener, CompoundButton.OnCheckedChangeListener, SeekBar.OnSeekBarChangeListener {

    private ToggleButton onOffButton;

    private RadioButton radioButtonSine;
    private RadioButton radioButtonSquare;
    private RadioButton radioButtonSawtooth;
    private RadioButton radioButtonTriangular;

    private SeekBar seekBarFrequency;

    private ListView listViewEffects;

    private Synthesizer synth;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        if (!initializeEngine()) {

            Toast.makeText(this, "Engine Failed!", Toast.LENGTH_LONG).show();

            finish();

            return;
        }

        createUIElements();

        setUIListeners();

        radioButtonSine.setChecked(true);
    }

    @Override
    protected void onResume() {

        super.onResume();
        synth.start();
    }

    @Override
    protected void onPause() {

        synth.pause();
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
            case R.id.toggleOnOffButton:

                if (onOffButton.isChecked()) {

                    synth.setSynthesis(true);

                } else {

                    synth.setSynthesis(false);
                }

                break;
        }
    }

    @Override
    public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {

        setSynthesizerWaveType();
    }

    @Override
    public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {

        synth.setFromWaveFrequencyMap(seekBar.getProgress());
    }

    @Override
    public void onStartTrackingTouch(SeekBar seekBar) {

    }

    @Override
    public void onStopTrackingTouch(SeekBar seekBar) {

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

        return synth.initialize(sampleRate, WaveType.Sine, 440);
    }

    private void setListView() {


        LinkedList<DenizonEffectParameter> paramList = new LinkedList<>();
        paramList.add(new DenizonEffectParameter("param_name", 0, 100, 50));

        LinkedList<DenizonEffect> effectList = new LinkedList<>();
        for (int i = 0; i < 7; i++) {
            effectList.add(new DenizonEffect("effect_" + i, true, paramList));
        }

        EffectListArrayAdapter effectListArrayAdapter = new EffectListArrayAdapter(this, effectList);

        listViewEffects.setAdapter(effectListArrayAdapter);
    }

    private void createUIElements() {

        this.onOffButton = findViewById(R.id.toggleOnOffButton);

        this.radioButtonSine = findViewById(R.id.radioButtonSine);
        this.radioButtonSquare = findViewById(R.id.radioButtonSquare);
        this.radioButtonSawtooth = findViewById(R.id.radioButtonSawtooth);
        this.radioButtonTriangular = findViewById(R.id.radioButtonTriangular);

        this.seekBarFrequency = findViewById(R.id.seekBarFrequency);

        this.listViewEffects = findViewById(R.id.listViewEffects);
    }

    private void setUIListeners() {

        onOffButton.setOnClickListener(this);

        radioButtonSine.setOnCheckedChangeListener(this);
        radioButtonSquare.setOnCheckedChangeListener(this);
        radioButtonSawtooth.setOnCheckedChangeListener(this);
        radioButtonTriangular.setOnCheckedChangeListener(this);

        seekBarFrequency.setOnSeekBarChangeListener(this);
    }

    private void setSynthesizerWaveType() {

        WaveType waveType = WaveType.Sine;

        if (radioButtonSquare.isChecked()) {

            waveType = WaveType.Square;

        } else if (radioButtonSawtooth.isChecked()) {

            waveType = WaveType.Sawtooth;

        } else if (radioButtonTriangular.isChecked()) {

            waveType = WaveType.Triangular;
        }

        synth.setActiveWaveType(waveType);
    }
}
