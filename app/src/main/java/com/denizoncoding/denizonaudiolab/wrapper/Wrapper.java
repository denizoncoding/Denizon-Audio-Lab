package com.denizoncoding.denizonaudiolab.wrapper;

public class Wrapper {

    public native long[] getGeneratorIds();

    public native long[] getEffectIds();

    public native String getEffectNameFromId(long id);

    public native long[] getParameterIdArray(long id);

    public native String getParameterNameFromId(long parameterId);

    public native boolean isParameterSwitchable(long parameterId);

    public native void setNameWithId(long id);

    public native void setParameterIn100RangeWithId(long parameterId, float value);

    public native float getParameterMinFromId(long parameterId);

    public native float getParameterValueFromId(long parameterId);

    public native float getParameterMaxFromId(long parameterId);
}
