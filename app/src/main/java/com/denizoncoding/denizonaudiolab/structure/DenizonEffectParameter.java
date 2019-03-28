package com.denizoncoding.denizonaudiolab.structure;

public class DenizonEffectParameter {

    String name;
    int min;
    int max;
    int value;

    public DenizonEffectParameter(String name, int min, int max, int value) {

        this.name = name;
        this.min = min;
        this.max = max;
        this.value = value;
    }

    public String getName() {
        return name;
    }

    public int getMin() {
        return min;
    }

    public int getMax() {
        return max;
    }

    public int getValue() {
        return value;
    }

    public void setValue(int value) {
        this.value = value;
    }
}
