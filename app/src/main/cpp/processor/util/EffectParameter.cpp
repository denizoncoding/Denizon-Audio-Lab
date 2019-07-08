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

#include "EffectParameter.h"

EffectParameter::EffectParameter(string parameterName_, float minLevel_, float maxLevel_,
                                 float currentLevel_) {

    parameterName = parameterName_;
    minLevel = minLevel_;
    maxLevel = maxLevel_;
    currentLevel = currentLevel_;

}

void EffectParameter::setLevel(float currentLevel_) {

    currentLevel = currentLevel_;
}

float EffectParameter::getCurrentLevel() {

    return currentLevel;
}

float EffectParameter::getMinLevel() {

    return minLevel;
}

float EffectParameter::getMaxLevel() {

    return maxLevel;
}

string EffectParameter::getParameterName() {

    return parameterName;
}