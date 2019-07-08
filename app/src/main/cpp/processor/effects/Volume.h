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
// Created by deniz on 9.06.2019.
//

#pragma once

#include "../util/BaseEffect.h"

class Volume : public BaseEffect {

public:

    Volume() : BaseEffect() {

        setName("Volume");

        addEffectParameter(levelParameter);
    }

    void process(float *audioData, int numFrames) {

        for (int i = 0; i < numFrames; ++i) {

            audioData[i] = audioData[i] * levelParameter.getCurrentLevel();
        }
    }

private :

    EffectParameter levelParameter = EffectParameter("Level", 0.0f, 1.0f, 0.9f);

};


