package com.denizoncoding.denizonaudiolab.structure;

import java.util.LinkedList;

public class DenizonEffect {

    String name;
    boolean isOn;
    LinkedList<DenizonEffectParameter> parameters = new LinkedList<>();

    public DenizonEffect(String name, boolean isOn, LinkedList<DenizonEffectParameter> effects) {
        this.name = name;
        this.isOn = isOn;
        this.parameters = effects;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public boolean isOn() {
        return isOn;
    }

    public void setOn(boolean on) {
        isOn = on;
    }

    public LinkedList<DenizonEffectParameter> getParameters() {
        return parameters;
    }

    public void setParameters(LinkedList<DenizonEffectParameter> parameters) {
        this.parameters = parameters;
    }

}
