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

#pragma once

#include <string>

using namespace std;


class EffectParameter {

public:
    EffectParameter(const string &name, float min, float max, float value) : name(name), min(min),
                                                                             max(max),
                                                                             value(value) {
        isSwitchable = false;
    }

    EffectParameter(const string &name, float value) : name(name), min(0),
                                                       max(1),
                                                       value(value) {

        isSwitchable = true;
    }

    bool isIsSwitchable() const {
        return isSwitchable;
    }

    const string &getName() const {
        return name;
    }

    float getMin() const {
        return min;
    }

    float getMax() const {
        return max;
    }

    float getValue() const {
        return value;
    }

    void setValue(float newValue) {

        EffectParameter::value = (((max - min)) * newValue) + min;
    }

    string *getSwitches() const {
        return switches;
    }

private:

    bool isSwitchable;
    string name;
    float min;
    float max;
    float value;
    string *switches;


};


