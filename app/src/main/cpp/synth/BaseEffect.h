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

#include <string>
#include "EffectParameter.h"
#include <vector>
#include <math.h>

#define M_PI 3.14159265358979323846

using namespace std;

class BaseEffect {

public:

    BaseEffect(string name, float sampleFrequency) {

        this->name = name;
        this->sampleFrequency = sampleFrequency;
        parameters = new vector<long>();
    }

    virtual void process(float *audioData, int numFrames, bool isAdding) {

    }

    virtual void resetDsp() {

    }

    string getName() {

        return name;
    }

    void setName(string name) {

        this->name = name;
    }

    vector<long> getParameters() {

        return *parameters;
    }

protected:
    vector<long> *parameters;
    string name = "unknown";
    float sampleFrequency = 44100;

};
