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

#include "Processor.h"


void Processor::addGenerator(BaseEffect *effect) {

    generatorsVector->push_back((long) effect);
}

const vector<long> Processor::getGenerators() {

    return *generatorsVector;
}

void Processor::addEffect(BaseEffect *effect) {

    effectsVector->push_back((long) effect);
}

const vector<long> Processor::getEffects() {

    return *effectsVector;
}

void Processor::processGenerators(float *audioData, int numFrames) {

    const vector<long> &vector = getGenerators();

    int size = vector.size();

    for (int i = 0; i < size; i++) {

        ((BaseEffect *) vector[i])->process(audioData, numFrames, i != 0);
    }
}

void Processor::processWithEffects(float *audioData, int numFrames) {

    const vector<long> &vector = getEffects();

    int size = vector.size();

    for (int i = 0; i < size; i++) {

        ((BaseEffect *) vector[i])->process(audioData, numFrames, false);
    }
}
