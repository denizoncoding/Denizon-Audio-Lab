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
// Created by deniz on 1.08.2019.
//

#include "../BaseEffect.h"

class Tremolo : public BaseEffect {

private:
    EffectParameter *bypass;
    EffectParameter *phase;
    EffectParameter *level;
    int phaseSamples = 0;
    float phaseSampleCounter = 0;
    bool ascending = true;

public:

    Tremolo(float sampleFrequency) : BaseEffect("Tremolo", sampleFrequency) {

        bypass = new EffectParameter("Bypass", 1);
        parameters->push_back((long) bypass);

        phase = new EffectParameter("Phase", 0, 1, 0.5f);
        parameters->push_back((long) phase);

        level = new EffectParameter("Level", 0.1, 0.9, 0.5f);
        parameters->push_back((long) level);

        phaseSamples = phase->getValue() * sampleFrequency;
    }

    void process(float *audioData, int numFrames, bool isAdding) {

        if (bypass->getValue() == 0) {

            return;
        }

        if (phaseSamples != phase->getValue() * sampleFrequency) {

            phaseSamples = phase->getValue() * sampleFrequency;
            phaseSampleCounter = 0;
        }

        for (int i = 0; i < numFrames; i++) {

            audioData[i] = audioData[i] * (phaseSampleCounter / phaseSamples) * level->getValue();

            if (ascending) {

                phaseSampleCounter++;
            } else {

                phaseSampleCounter--;
            }

            if (phaseSampleCounter >= phaseSamples) {

                ascending = false;
                phaseSampleCounter = phaseSamples;
            }

            if (phaseSampleCounter <= 0) {

                ascending = true;
                phaseSampleCounter = 0;
            }
        }

    }
};


