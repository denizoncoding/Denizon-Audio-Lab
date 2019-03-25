package com.denizoncoding.denizonaudiolab;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.CompoundButton;
import android.widget.RadioButton;
import android.widget.SeekBar;
import android.widget.TextView;
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

    }

    private void createUIElements() {

        onOffbutton = findViewById(R.id.toggleButton);

        radioButtonSine = findViewById(R.id.radioButtonSine);
        radioButtonSquare = findViewById(R.id.radioButtonSquare);
        radioButtonSawtooth = findViewById(R.id.radioButtonSawtooth);
        radioButtonTriangular = findViewById(R.id.radioButtonTriangular);

        seekBarFrequency = findViewById(R.id.seekBarFrequency);

    }

    private void setUIListeners() {

        onOffbutton.setOnClickListener(this);

        radioButtonSine.setOnCheckedChangeListener(this);
        radioButtonSine.setOnCheckedChangeListener(this);
        radioButtonSine.setOnCheckedChangeListener(this);
        radioButtonSine.setOnCheckedChangeListener(this);

        seekBarFrequency.setOnSeekBarChangeListener(this);
    }

    @Override
    public void onClick(View v) {

    }

    @Override
    public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {

    }

    @Override
    public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {

    }

    @Override
    public void onStartTrackingTouch(SeekBar seekBar) {

    }

    @Override
    public void onStopTrackingTouch(SeekBar seekBar) {

    }
}
