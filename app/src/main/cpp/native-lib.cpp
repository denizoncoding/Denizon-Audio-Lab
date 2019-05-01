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
#include <string>
#include <oboe/Oboe.h>
#include "DenizonEngine.h"
#include "synth/Oscillator.h"

extern "C" {

DenizonEngine *engine;
Oscillator *osc;

//JNIEXPORT jstring JNICALL
//Java_com_denizoncoding_denizonaudiolab_MainActivity_stringFromJNI(
//        JNIEnv *env,
//        jobject /* this */) {
//    std::string hello = "Hello from C++";
//    return env->NewStringUTF(hello.c_str());
//}

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

JNIEXPORT jboolean JNICALL
Java_com_denizoncoding_denizonaudiolab_synth_Synthesizer_startEngine(JNIEnv *env,
                                                                     jobject instance) {

    return static_cast<jboolean>(engine->start());
}

JNIEXPORT jboolean JNICALL
Java_com_denizoncoding_denizonaudiolab_synth_Synthesizer_pauseEngine(JNIEnv *env,
                                                                     jobject instance) {

    return static_cast<jboolean>(engine->pause());
}

JNIEXPORT jboolean JNICALL
Java_com_denizoncoding_denizonaudiolab_synth_Synthesizer_flushEngine(JNIEnv *env,
                                                                     jobject instance) {

    return static_cast<jboolean>(engine->flush());
}

JNIEXPORT jboolean JNICALL
Java_com_denizoncoding_denizonaudiolab_synth_Synthesizer_stopEngine(JNIEnv *env, jobject instance) {

    return static_cast<jboolean>(engine->stop());
}

JNIEXPORT void JNICALL
Java_com_denizoncoding_denizonaudiolab_synth_Synthesizer_closeEngine(JNIEnv *env,
                                                                     jobject instance) {

    engine->close();
}

JNIEXPORT void JNICALL
Java_com_denizoncoding_denizonaudiolab_synth_Synthesizer_runEngine(JNIEnv *env, jobject instance,
                                                                   jboolean onOff) {

    osc->setOn(onOff);
}

JNIEXPORT void JNICALL
Java_com_denizoncoding_denizonaudiolab_synth_Synthesizer_setWaveType(JNIEnv *env, jobject instance,
                                                                     jint waveType) {

    osc->setWaveType(waveType);

}

JNIEXPORT void JNICALL
Java_com_denizoncoding_denizonaudiolab_synth_Synthesizer_setFrequency(JNIEnv *env, jobject instance,
                                                                      jfloat freq) {

    osc->setFrequency(freq);

}
}