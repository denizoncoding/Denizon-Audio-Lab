package com.denizoncoding.denizonaudiolab.synth;

import android.util.Log;

import com.denizoncoding.denizonaudiolab.wrapper.Wrapper;

public class EffectParameter {

    private long parameterId;
    private boolean isSwitchable;
    private String name;
    private float min;
    private float max;
    private float value;
    Wrapper wrapper;

    public EffectParameter(Wrapper wrapper, long parameterId, String name, boolean isSwitchable, float min, float max, float value) {

        this.wrapper = wrapper;
        this.parameterId = parameterId;
        this.isSwitchable = isSwitchable;
        this.name = name;
        this.min = min;
        this.max = max;
        this.value = value;
        Log.v("EffectParameter", name + " " + min + " " + max + " " + value);
    }

    public boolean isSwitchable() {

        return isSwitchable;
    }

    public String getName() {

        return name;
    }

    public void setName(String name) {

        this.name = name;
    }

    public float getMin() {

        return min;
    }

    public float getMax() {

        return max;
    }

    public float getValue() {

        return value;
    }

    public void setValue(float value) {

        wrapper.setParameterWithId(this.parameterId, value);
        this.value = value;
    }
}
