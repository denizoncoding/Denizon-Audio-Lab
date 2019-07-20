package com.denizoncoding.denizonaudiolab.wrapper;

import com.denizoncoding.denizonaudiolab.synth.Effect;
import com.denizoncoding.denizonaudiolab.synth.EffectParameter;

import java.util.ArrayList;
import java.util.List;

public class ObjectGenerator {

    private Wrapper wrapper;

    public ObjectGenerator(Wrapper wrapper) {

        this.wrapper = wrapper;
    }

    public List<Effect> getAll() {

        List<Effect> effectList = new ArrayList<>();


        addEffectsToList(effectList, wrapper.getGeneratorIds());

        addEffectsToList(effectList, wrapper.getEffectIds());

        return effectList;
    }

    private void addEffectsToList(List<Effect> effectList, long[] effectIdArray) {
        for (long effectId : effectIdArray) {

            String effectName = wrapper.getEffectNameFromId(effectId);

            List<EffectParameter> parameterList = new ArrayList<>();

            long[] parameterIdArray = wrapper.getParameterIdArray(effectId);

            for (long parameterId : parameterIdArray) {

                String parameterName = wrapper.getParameterNameFromId(parameterId);

                parameterList.add(new EffectParameter(wrapper, parameterId, parameterName, wrapper.isParameterSwitchable(parameterId), wrapper.getParameterMinFromId(parameterId),
                        wrapper.getParameterMaxFromId(parameterId), wrapper.getParameterValueFromId(parameterId)));
            }

            effectList.add(new Effect(effectId, effectName, parameterList));
        }
    }

}
