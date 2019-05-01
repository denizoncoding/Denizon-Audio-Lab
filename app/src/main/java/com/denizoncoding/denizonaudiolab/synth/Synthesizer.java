package com.denizoncoding.denizonaudiolab.synth;

import java.util.ArrayList;

public class Synthesizer {

    int sampleRate;
    WaveType activeWaveType;
    float activeWaveFrequency;

    float[] definedWaveFrequencies = new float[]{220f, 261.63f, 293.66f, 329.63f, 392f, 415.30f, 440f, 523.25f, 587.33f, 622.25f};

    static {
        System.loadLibrary("native-lib");
    }

    private native boolean initEngine();

    private native boolean startEngine();

    private native boolean pauseEngine();

    private native boolean flushEngine();

    private native boolean stopEngine();

    private native void closeEngine();

    private native void runEngine(boolean onOff);


    public Synthesizer(int sampleRate) {

    }

    public boolean initialize(WaveType initWaveType, int initFrequency) {

        return false;
    }

    public boolean start() {

        return startEngine();
    }

    public boolean pause() {

        return pauseEngine();
    }

    public boolean destroy() {

        if (!flushEngine()) {

            return false;
        }

        if (!stopEngine()) {

            return false;
        }

        closeEngine();

        return false;
    }

    public void setSynthesis(boolean on) {

        runEngine(on);
    }

    public int getSampleRate() {

        return sampleRate;
    }

    public WaveType getActiveWaveType() {

        return activeWaveType;
    }

    public void setActiveWaveType(WaveType activeWaveType) {

        this.activeWaveType = activeWaveType;
    }

    public float getActiveWaveFrequency() {

        return activeWaveFrequency;
    }

    public void setActiveWaveFrequency(float activeWaveFrequency) {

        this.activeWaveFrequency = activeWaveFrequency;
    }

    public void setFromWaveFrequencyMap(int progress) {

        setActiveWaveFrequency(definedWaveFrequencies[progress]);
    }
}
