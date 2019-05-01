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

#include "Oscillator.h"


Oscillator::Oscillator(int sampleFrequency, int waveType, float waveFrequency) {

    this->sampleFrequency = sampleFrequency;
    setWaveType(waveType);
    setFrequency(waveFrequency);
}

void Oscillator::render(float *audioData, int numFrames) {

    if (isRendering) {

        for (int i = 0; i < numFrames; i++) {

            audioData[i] = 0.5f;
        }
    } else {

        for (int i = 0; i < numFrames; i++) {

            audioData[i] = 0.0f;
        }
    }
}

void Oscillator::setOn(bool isOn) {

    this->isRendering = isOn;
}

void Oscillator::setFrequency(float freq) {

    this->waveFrequency = freq;
}

void Oscillator::setWaveType(int waveTypeNumber) {

    this->waveType = Sine;

    switch (waveTypeNumber) {
        case 1:
            this->waveType = Square;
            break;
        case 2:
            this->waveType = Triangular;
            break;
        case 3:
            this->waveType = Sawtooth;
            break;
        default:
            break;
    }
}


