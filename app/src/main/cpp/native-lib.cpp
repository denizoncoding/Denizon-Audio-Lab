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
#include "synth/effects/Volume.h"
#include "synth/generators/SineGenerator.h"


DenizonEngine *engine;

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_denizoncoding_denizonaudiolab_synth_Synthesizer_initEngine(JNIEnv *env, jobject instance,
                                                                    jint sampleRate,
                                                                    jfloat initFrequency) {

    engine = new DenizonEngine(sampleRate);
    engine->getProcessor()->addGenerator(new SineGenerator(sampleRate));
    engine->getProcessor()->addEffect(new Volume(sampleRate));
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

}

extern "C"
JNIEXPORT void JNICALL
Java_com_denizoncoding_denizonaudiolab_synth_Synthesizer_setWaveType(JNIEnv *env, jobject instance,
                                                                     jint waveType) {


}

extern "C"
JNIEXPORT void JNICALL
Java_com_denizoncoding_denizonaudiolab_synth_Synthesizer_setFrequency(JNIEnv *env, jobject instance,
                                                                      jfloat freq) {


}
extern "C"
JNIEXPORT jlongArray JNICALL
Java_com_denizoncoding_denizonaudiolab_wrapper_Wrapper_getGeneratorIds(JNIEnv *env,
                                                                       jobject instance) {

    const vector<long> &vector = engine->getProcessor()->getGenerators();

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
JNIEXPORT jlongArray JNICALL
Java_com_denizoncoding_denizonaudiolab_wrapper_Wrapper_getEffectIds(JNIEnv *env, jobject instance) {

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
Java_com_denizoncoding_denizonaudiolab_wrapper_Wrapper_getEffectNameFromId(JNIEnv *env,
                                                                           jobject instance,
                                                                           jlong id) {

    // TODO


    return env->NewStringUTF(((BaseEffect *) id)->getName().c_str());
}
extern "C"
JNIEXPORT void JNICALL
Java_com_denizoncoding_denizonaudiolab_wrapper_Wrapper_setNameWithId(JNIEnv *env, jobject instance,
                                                                     jlong id) {


    ((BaseEffect *) id)->setName("changed");
}

extern "C"
JNIEXPORT jlongArray JNICALL
Java_com_denizoncoding_denizonaudiolab_wrapper_Wrapper_getParameterIdArray(JNIEnv *env,
                                                                           jobject instance,
                                                                           jlong id) {

    const vector<long> &vector = ((BaseEffect *) id)->getParameters();

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
Java_com_denizoncoding_denizonaudiolab_wrapper_Wrapper_getParameterNameFromId(JNIEnv *env,
                                                                              jobject instance,
                                                                              jlong parameterId) {


    return env->NewStringUTF(((EffectParameter *) parameterId)->getName().c_str());
}

extern "C"
JNIEXPORT void JNICALL
Java_com_denizoncoding_denizonaudiolab_wrapper_Wrapper_setParameterWithId(JNIEnv *env,
                                                                          jobject instance,
                                                                          jlong parameterId,
                                                                          jfloat value) {

    ((EffectParameter *) parameterId)->setValue(value);
}

extern "C"
JNIEXPORT jboolean JNICALL
Java_com_denizoncoding_denizonaudiolab_wrapper_Wrapper_isParameterSwitchable(JNIEnv *env,
                                                                             jobject instance,
                                                                             jlong parameterId) {

    return ((EffectParameter *) parameterId)->isIsSwitchable();

}

extern "C"
JNIEXPORT jfloat JNICALL
Java_com_denizoncoding_denizonaudiolab_wrapper_Wrapper_getParameterMinFromId(JNIEnv *env,
                                                                             jobject instance,
                                                                             jlong parameterId) {

    return ((EffectParameter *) parameterId)->getMin();
}

extern "C"
JNIEXPORT jfloat JNICALL
Java_com_denizoncoding_denizonaudiolab_wrapper_Wrapper_getParameterValueFromId(JNIEnv *env,
                                                                               jobject instance,
                                                                               jlong parameterId) {

    return ((EffectParameter *) parameterId)->getValue();
}

extern "C"
JNIEXPORT jfloat JNICALL
Java_com_denizoncoding_denizonaudiolab_wrapper_Wrapper_getParameterMaxFromId(JNIEnv *env,
                                                                             jobject instance,
                                                                             jlong parameterId) {

    return ((EffectParameter *) parameterId)->getMax();
}