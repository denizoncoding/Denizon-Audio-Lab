package com.denizoncoding.denizonaudiolab.synth;

import java.util.List;

public class Effect {

    long id;
    String name;
    List<EffectParameter> parameterList;

    public Effect(long id, String name, List<EffectParameter> parameterList) {

        this.id = id;
        this.name = name;
        this.parameterList = parameterList;
    }

    public long getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public List<EffectParameter> getParameterList() {
        return parameterList;
    }

}
