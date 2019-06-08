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

#include <android/log.h>
#include "Oscillator.h"


Oscillator::Oscillator(int sampleFrequency, int waveType, float waveFrequency) {

    this->sampleFrequency = sampleFrequency;

    setWaveType(waveType);
    setFrequency(waveFrequency);
}

void Oscillator::setOn(bool isOn) {

    this->isRendering = isOn;
}

void Oscillator::setFrequency(float freq) {

    waveFrequency = freq;
    phaseSumSine = (float) (2.0f * M_PI * waveFrequency) / sampleFrequency;
    samplesInHalfPeriode = (int) (sampleFrequency / (2.0f * waveFrequency));
}

void Oscillator::setWaveType(int waveTypeNumber) {

    waveType = Sine;

    switch (waveTypeNumber) {
        case 1:
            waveType = Square;
            break;
        case 2:
            waveType = Triangular;
            break;
        case 3:
            waveType = Sawtooth;
            break;
        default:
            break;
    }
}

void Oscillator::render(float *audioData, int numFrames) {

    switch (waveType) {
        case Square:
            generateSquareWave(audioData, numFrames);
            break;
        case Sawtooth:
            generateSawtoohWave(audioData, numFrames);
            break;
        case Triangular:
            generateTriangularWave(audioData, numFrames);
            break;
        default:
            generateSineWave(audioData, numFrames);
            break;
    }

}

void Oscillator::generateSineWave(float *audioData, int32_t numFrames) {

    for (int i = 0; i < numFrames; i++) {

        if (isRendering) {

            audioData[i] = sin(phase);

            phase += phaseSumSine;

            if (phase > 2 * M_PI) {

                phase -= 2 * M_PI;
            }

        } else {

            audioData[i] = 0;
        }
    }
}

void Oscillator::generateSquareWave(float *audioData, int32_t numFrames) {

    for (int i = 0; i < numFrames; i++) {

        if (isRendering) {

            if (phaseCounter <= samplesInHalfPeriode) {

                audioData[i] = 1;

            } else {

                audioData[i] = 0;

            }
            phaseCounter++;

            if (phaseCounter >= 2 * samplesInHalfPeriode) {

                phaseCounter = 0;
            }
        } else {

            audioData[i] = 0;
        }
    }
}

void Oscillator::generateSawtoohWave(float *audioData, int32_t numFrames) {

    for (int i = 0; i < numFrames; i++) {

        if (isRendering) {

            audioData[i] = (1 / (2.0f * samplesInHalfPeriode)) * phaseCounter;

            phaseCounter++;

            if (phaseCounter >= 2 * samplesInHalfPeriode) {

                phaseCounter = 0;
            }

        } else {

            audioData[i] = 0;
        }
    }
}

void Oscillator::generateTriangularWave(float *audioData, int32_t numFrames) {

    for (int i = 0; i < numFrames; i++) {

        if (isRendering) {

            if (phaseCounter <= samplesInHalfPeriode) {

                audioData[i] = (1 / ((float) samplesInHalfPeriode)) * phaseCounter;

            } else {

                audioData[i] =
                        1 - ((1 / ((float) samplesInHalfPeriode)) *
                             (phaseCounter - samplesInHalfPeriode));
            }

            phaseCounter++;

            if (phaseCounter >= 2 * samplesInHalfPeriode) {

                phaseCounter = 0;
            }

        } else {

            audioData[i] = 0;
        }
    }
}

