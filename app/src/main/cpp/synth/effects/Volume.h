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
// Created by deniz on 14.07.2019.
//




#include "../BaseEffect.h"

class Volume : public BaseEffect {


private:
    EffectParameter *bypass;
    EffectParameter *level;

public:

    Volume(float sampleFrequency) : BaseEffect("Volume", sampleFrequency) {

        bypass = new EffectParameter("Bypass", 1);
        parameters->push_back((long) bypass);

        level = new EffectParameter("Level", 0, 1, 0.9f);
        parameters->push_back((long) level);
    }

    void process(float *audioData, int numFrames, bool isAdding) {

        if (bypass->getValue() == 0) {

            return;
        }

        for (int i = 0; i < numFrames; i++) {

            audioData[i] = audioData[i] * level->getValue();
        }
    }

};


