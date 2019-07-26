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
// Created by deniz on 26.07.2019.
//

#include "../BaseEffect.h"

class Delay : public BaseEffect {

private:
    EffectParameter *bypass;
    EffectParameter *delayTime;
    EffectParameter *feedback;

    float *feedbackBuffer;
    int bufferReadPointer = 0;
    int bufferWritePointer = 0;
    int lastBufferSize = 0;

public:

    Delay(float sampleFrequency) : BaseEffect("Delay", sampleFrequency) {

        bypass = new EffectParameter("Bypass", 1);
        parameters->push_back((long) bypass);

        delayTime = new EffectParameter("Delay", 0, 2, 0.3f);
        parameters->push_back((long) delayTime);

        feedback = new EffectParameter("Feedback", 0, 1, 0.7f);
        parameters->push_back((long) feedback);

        lastBufferSize = delayTime->getValue() * sampleFrequency;
        feedbackBuffer = new float[lastBufferSize];
    }


    void process(float *audioData, int numFrames, bool isAdding) {

        if (bypass->getValue() == 0) {

            return;
        }

        if (lastBufferSize != delayTime->getValue() * sampleFrequency) {

            bufferWritePointer = 0;
            lastBufferSize = 0;
            lastBufferSize = delayTime->getValue() * sampleFrequency;
            feedbackBuffer = new float[lastBufferSize];
        }

        float feedbackVolume = feedback->getValue();

        for (int i = 0; i < numFrames; i++) {

            if (bufferReadPointer >= lastBufferSize) {

                bufferReadPointer = 0;
            }

            audioData[i] = (audioData[i] + feedbackBuffer[bufferReadPointer] * feedbackVolume) / 2;
            bufferReadPointer++;

            if (bufferWritePointer >= lastBufferSize) {

                bufferWritePointer = 0;
            }

            feedbackBuffer[bufferWritePointer] = audioData[i];
            bufferWritePointer++;
        }

    }
};


