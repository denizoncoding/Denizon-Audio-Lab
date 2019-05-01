/*
 * Copyright 2019 Deniz A. ATLIHAN
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

#ifndef DENIZON_AUDIO_LAB_OSCILLATOR_H
#define DENIZON_AUDIO_LAB_OSCILLATOR_H

#include <jni.h>
#include "WaveType.h"

class Oscillator {

public:

    Oscillator(int sampleFrequency, int waveType, float waveFrequency);

    void render(float *audioData, int numFrames);

    void setOn(bool isOn);

    void setFrequency(float freq);

    void setWaveType(int type);

private:

    int sampleFrequency;
    bool isRendering = false;
    WaveType waveType;
    float waveFrequency;
    // std::atomic<bool> isRendering{false};

};

#endif //DENIZON_AUDIO_LAB_OSCILLATOR_H