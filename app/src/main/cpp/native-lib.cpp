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

#include <jni.h>
#include "engine/DenizonEngine.h"
#include "oscillator/Oscillator.h"
#include "processor/effects/Volume.h"


DenizonEngine *engine;
Oscillator *osc;

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_denizoncoding_denizonaudiolab_synth_Synthesizer_initEngine(JNIEnv *env, jobject instance,
                                                                    jint sampleRate,
                                                                    jint initWaveType,
                                                                    jfloat initFrequency) {

    engine = new DenizonEngine(sampleRate);
    osc = new Oscillator(sampleRate, initWaveType, initFrequency);

    engine->setOscillator(osc);

    return static_cast<jboolean>(engine->init());
}

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_denizoncoding_denizonaudiolab_synth_Synthesizer_startEngine(JNIEnv *env,
                                                                     jobject instance) {

    return static_cast<jboolean>(engine->start());
}

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_denizoncoding_denizonaudiolab_synth_Synthesizer_pauseEngine(JNIEnv *env,
                                                                     jobject instance) {

    return static_cast<jboolean>(engine->pause());
}

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_denizoncoding_denizonaudiolab_synth_Synthesizer_flushEngine(JNIEnv *env,
                                                                     jobject instance) {

    return static_cast<jboolean>(engine->flush());
}

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_denizoncoding_denizonaudiolab_synth_Synthesizer_stopEngine(JNIEnv *env, jobject instance) {

    return static_cast<jboolean>(engine->stop());
}

extern "C"
JNIEXPORT void JNICALL
Java_com_denizoncoding_denizonaudiolab_synth_Synthesizer_closeEngine(JNIEnv *env,
                                                                     jobject instance) {

    engine->close();
}

extern "C"
JNIEXPORT void JNICALL
Java_com_denizoncoding_denizonaudiolab_synth_Synthesizer_runEngine(JNIEnv *env, jobject instance,
                                                                   jboolean onOff) {

    osc->setOn(onOff);
}

extern "C"
JNIEXPORT void JNICALL
Java_com_denizoncoding_denizonaudiolab_synth_Synthesizer_setWaveType(JNIEnv *env, jobject instance,
                                                                     jint waveType) {

    osc->setWaveType(waveType);

}

extern "C"
JNIEXPORT void JNICALL
Java_com_denizoncoding_denizonaudiolab_synth_Synthesizer_setFrequency(JNIEnv *env, jobject instance,
                                                                      jfloat freq) {

    osc->setFrequency(freq);

}
extern "C"
JNIEXPORT jlongArray JNICALL
Java_com_denizoncoding_denizonaudiolab_wrapper_Wrapper_getIdList(JNIEnv *env, jobject instance) {

    const vector<long> &vector = engine->getProcessor()->getEffects();

    int size = vector.size();

    jlongArray result = static_cast<jlongArray>(env->NewLongArray(size));

    if (result == NULL) {

        return nullptr;
    }

    jlong fill[vector.size()];

    for (int i = 0; i < size; i++) {
        fill[i] = vector[i];
    }

    env->SetLongArrayRegion(result, 0, size, fill);

    return result;
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_denizoncoding_denizonaudiolab_wrapper_Wrapper_getNameFromId(JNIEnv *env, jobject instance,
                                                                     jlong id) {

    // TODO


    return env->NewStringUTF(((BaseEffect *) id)->getName().c_str());
}extern "C"
JNIEXPORT void JNICALL
Java_com_denizoncoding_denizonaudiolab_wrapper_Wrapper_setNameWithId(JNIEnv *env, jobject instance,
                                                                     jlong id) {


    ((BaseEffect *) id)->setName("changed");
}