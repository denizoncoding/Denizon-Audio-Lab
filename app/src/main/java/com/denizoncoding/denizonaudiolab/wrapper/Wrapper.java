package com.denizoncoding.denizonaudiolab.wrapper;

public class Wrapper {

    private native long[] getIdList();

    public native String getNameFromId(long id);

    public native void setNameWithId(long id);


    public long getId() {

        return getIdList()[0];
    }

}
