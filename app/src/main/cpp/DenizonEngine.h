//
// Created by deniz on 9.04.2019.
//

#ifndef DENİZON_AUDİO_LAB_DENİZONENGİNE_H
#define DENİZON_AUDİO_LAB_DENİZONENGİNE_H


#include <oboe/Oboe.h>
#include <vector>
#include "synth/WaveType.h"

using namespace oboe;

class DenizonEngine : AudioStreamCallback {

    // TODO: usage of isInitialized and isStarted
    // TODO: waitForStateChange algorithms
    // TODO: discconect handle

public:

    DenizonEngine(int sampleRate);

    bool init();

    bool start();

    bool pause();

    bool stop();

    bool flush();

    void close();

    bool setOn(bool isOn);

    void setFrequency(float freq);

    void setWaveType(WaveType type);

private:

    AudioStreamBuilder *streamBuilder;
    AudioStream *stream;

    Result lastResult = Result::ErrorNull;

    bool isInitialized = false;
    bool isStarted = false;

    int sampleRate;

};


#endif //DENİZON_AUDİO_LAB_DENİZONENGİNE_H
