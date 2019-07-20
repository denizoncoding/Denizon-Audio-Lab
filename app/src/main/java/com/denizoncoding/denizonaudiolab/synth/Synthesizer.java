package com.denizoncoding.denizonaudiolab.synth;

public class Synthesizer {

    int sampleRate;
    float activeWaveFrequency;

    float[] definedWaveFrequencies = new float[]{220f, 261.63f, 293.66f, 329.63f, 392f, 415.30f, 440f, 523.25f, 587.33f, 622.25f};

    static {
        System.loadLibrary("native-lib");
    }

    private native boolean initEngine(int sampleRate, float initFrequency);

    private native boolean startEngine();

    private native boolean pauseEngine();

    private native boolean flushEngine();

    private native boolean stopEngine();

    private native void closeEngine();

    private native void runEngine(boolean onOff);

    private native void setFrequency(float freq);


    public boolean initialize(int sampleRate, float initFrequency) {

        return initEngine(sampleRate, initFrequency);
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

        return true;
    }

    public void setSynthesis(boolean on) {

        runEngine(on);
    }

    public void setFromWaveFrequencyMap(int progress) {

        setActiveWaveFrequency(definedWaveFrequencies[progress]);
    }

    public void setActiveWaveFrequency(float activeWaveFrequency) {

        this.activeWaveFrequency = activeWaveFrequency;
        setFrequency(activeWaveFrequency);
    }
}
