package com.denizoncoding.denizonaudiolab;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.CompoundButton;
import android.widget.RadioButton;
import android.widget.SeekBar;
import android.widget.Toast;
import android.widget.ToggleButton;

public class MainActivity extends AppCompatActivity implements View.OnClickListener, CompoundButton.OnCheckedChangeListener, SeekBar.OnSeekBarChangeListener {

    static {
        System.loadLibrary("native-lib");
    }

    private ToggleButton onOffbutton;

    private RadioButton radioButtonSine;
    private RadioButton radioButtonSquare;
    private RadioButton radioButtonSawtooth;
    private RadioButton radioButtonTriangular;

    private SeekBar seekBarFrequency;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        createUIElements();

        setUIListeners();

        radioButtonSine.setChecked(true);
    }

    private void createUIElements() {

        this.onOffbutton = findViewById(R.id.toggleOnOffButton);

        this.radioButtonSine = findViewById(R.id.radioButtonSine);
        this.radioButtonSquare = findViewById(R.id.radioButtonSquare);
        this.radioButtonSawtooth = findViewById(R.id.radioButtonSawtooth);
        this.radioButtonTriangular = findViewById(R.id.radioButtonTriangular);

        this.seekBarFrequency = findViewById(R.id.seekBarFrequency);

    }

    private void setUIListeners() {

        onOffbutton.setOnClickListener(this);

        radioButtonSine.setOnCheckedChangeListener(this);
        radioButtonSquare.setOnCheckedChangeListener(this);
        radioButtonSawtooth.setOnCheckedChangeListener(this);
        radioButtonTriangular.setOnCheckedChangeListener(this);

        seekBarFrequency.setOnSeekBarChangeListener(this);
    }

    @Override
    public void onClick(View v) {

        switch (v.getId()) {
            case R.id.toggleOnOffButton:
                if (onOffbutton.isChecked()) {

                    Toast.makeText(this, "On", Toast.LENGTH_SHORT).show();
                } else {

                    Toast.makeText(this, "Off", Toast.LENGTH_SHORT).show();
                }
                break;
        }
    }

    @Override
    public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {

        if (radioButtonSine.isChecked()) {

            Toast.makeText(this, "Sine", Toast.LENGTH_SHORT).show();
        } else if (radioButtonSquare.isChecked()) {

            Toast.makeText(this, "Square", Toast.LENGTH_SHORT).show();
        } else if (radioButtonSawtooth.isChecked()) {

            Toast.makeText(this, "Sawtooth", Toast.LENGTH_SHORT).show();
        } else if (radioButtonTriangular.isChecked()) {

            Toast.makeText(this, "Triangular", Toast.LENGTH_SHORT).show();
        }
    }

    @Override
    public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {

        Toast.makeText(this, "" + seekBar.getProgress(), Toast.LENGTH_SHORT).show();
    }

    @Override
    public void onStartTrackingTouch(SeekBar seekBar) {

    }

    @Override
    public void onStopTrackingTouch(SeekBar seekBar) {

    }
}
