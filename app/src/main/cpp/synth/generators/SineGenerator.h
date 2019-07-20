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
// Created by deniz on 20.07.2019.
//



#include "../BaseEffect.h"

class SineGenerator : public BaseEffect {

private:
    EffectParameter *bypass;
    EffectParameter *frequency;
    EffectParameter *level;
    int lastPhaseConstant;
    float *lastFreq = new float[4];
    std::mutex audioMutex;
public:

    SineGenerator(float sampleFrequency) : BaseEffect("Sine", sampleFrequency) {

        bypass = new EffectParameter("Bypass", 1);
        parameters->push_back((long) bypass);

        frequency = new EffectParameter("Frequency", 2, 1100, 440);
        parameters->push_back((long) frequency);

        level = new EffectParameter("Level", 0, 1, 0.5f);
        parameters->push_back((long) level);

        resetDsp();
    }

    void resetDsp() {

        lastPhaseConstant = 0;
    }

    void process(float *audioData, int numFrames, bool isAdding) {

        if (bypass->getValue() == 0) {

            return;
        }

//        float *complexData = new float[numFrames + 4];
//        memcpy(audioData, complexData, numFrames);
//        memmove(audioData, audioData + 3, numFrames);
//        memcpy(lastFreq, complexData, 4);

        int phaseConstant = (int) (sampleFrequency / frequency->getValue());

        float volume = level->getValue();
        audioMutex.lock();

        for (int i = 0; i < numFrames; i++) {

            float sineVal = static_cast<float>(sin(
                    (lastPhaseConstant * 2 * M_PI) / phaseConstant)
            );

            if (isAdding) {

                audioData[i] = (audioData[i] / 2 + sineVal);

            } else {

                audioData[i] = sineVal;
            }

            lastPhaseConstant++;

            if (lastPhaseConstant >= phaseConstant) {

                lastPhaseConstant -= phaseConstant;
            }
        }

        audioMutex.unlock();
    }
};


