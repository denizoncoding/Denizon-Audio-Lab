package com.denizoncoding.denizonaudiolab.synth;

public enum WaveType {

    Sine(0), Square(1), Triangular(2), Sawtooth(2);

    private final int type;

    WaveType(int type) {
        this.type = type;
    }

    public int getTypeNumber() {
        return this.type;
    }

}
