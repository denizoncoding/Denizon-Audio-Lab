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
// Created by deniz on 15.06.2019.
//

#pragma once

#include <list>
#include "BaseEffect.h"
#include "vector"

using namespace std;

class Processor {

public:

    Processor() {

        generatorsVector = new vector<long>();
        effectsVector = new vector<long>();
    }

    ~Processor() {

        delete effectsVector;
        delete generatorsVector;
    }

    void addGenerator(BaseEffect *effect);

    const vector<long> getGenerators();

    void addEffect(BaseEffect *effect);

    const vector<long> getEffects();

    BaseEffect *getEffect(int index);

    void processGenerators(float *audioData, int numFrames);

    void processWithEffects(float *audioData, int numFrames);

private:

    vector<long> *effectsVector;
    vector<long> *generatorsVector;

};


