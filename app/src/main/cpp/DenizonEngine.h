/*
 * Copyright 2019 Deniz A. Atlihan
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

//
// Created by deniz on 9.04.2019.
//

#ifndef DENIZON_AUDIO_LAB_DENIZONENGINE_H
#define DENIZON_AUDIO_LAB_DENIZONENGINE_H


#include <oboe/Oboe.h>
#include <vector>
#include "synth/WaveType.h"

using namespace oboe;

class DenizonEngine : AudioStreamCallback {

    // TODO: usage of isInitialized and isStarted
    // TODO: waitForStateChange algorithms
    // TODO: disconnect handle

public:

    DenizonEngine(int sampleRate);

    bool init();

    bool start();

    bool pause();

    bool stop();

    bool flush();

    void close();

    void setOn(bool isOn);

    void setFrequency(float freq);

    void setWaveType(WaveType type);

    DataCallbackResult onAudioReady(
            AudioStream *oboeStream,
            void *audioData,
            int32_t numFrames);

    void render(float *audioData, int32_t numFrames);

private:

    AudioStreamBuilder *streamBuilder;
    AudioStream *stream;

    Result lastResult = Result::ErrorNull;

    bool isInitialized = false;
    bool isStarted = false;
    bool isRendering = false;
    // std::atomic<bool> isRendering{false};
    int sampleRate;

};


#endif //DENIZON_AUDIO_LAB_DENIZONENGINE_H
