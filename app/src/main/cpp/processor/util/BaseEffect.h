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

#include "EffectParameter.h"

class BaseEffect {

public:

    BaseEffect() {

    }

//    void process(float *audioData, int numFrames) {
//
//    }

    virtual void process(float *audioData, int numFrames) {

    }

    list <string> getTypes() {

        return types;
    }

    list <EffectParameter> getParameters() {

        return parameters;
    }

    string getName() {

        return name;
    }

    void setName(string name_) {

        name = name_;
    }

protected:

    void addEffectParameter(EffectParameter parameter) {

        parameters.push_back(parameter);
    }


private:

    string name = "unknown";
    list <string> types;
    list <EffectParameter> parameters;


};


