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

extern "C" {
DenizonEngine *engine = new DenizonEngine(48000);

//JNIEXPORT jstring JNICALL
//Java_com_denizoncoding_denizonaudiolab_MainActivity_stringFromJNI(
//        JNIEnv *env,
//        jobject /* this */) {
//    std::string hello = "Hello from C++";
//    return env->NewStringUTF(hello.c_str());
//}

JNIEXPORT jboolean JNICALL
Java_com_denizoncoding_denizonaudiolab_MainActivity_initEngine(JNIEnv *env, jobject instance) {

    return engine->init();
}

JNIEXPORT jboolean JNICALL
Java_com_denizoncoding_denizonaudiolab_MainActivity_startEngine(JNIEnv *env, jobject instance) {

    return engine->start();
}

JNIEXPORT jboolean JNICALL
Java_com_denizoncoding_denizonaudiolab_MainActivity_pauseEngine(JNIEnv *env, jobject instance) {

    return engine->pause();
}

JNIEXPORT jboolean JNICALL
Java_com_denizoncoding_denizonaudiolab_MainActivity_stopEngine(JNIEnv *env, jobject instance) {

    return engine->stop();
}


JNIEXPORT jboolean JNICALL
Java_com_denizoncoding_denizonaudiolab_MainActivity_flushEngine(JNIEnv *env, jobject instance) {

    return engine->flush();
}

JNIEXPORT void JNICALL
Java_com_denizoncoding_denizonaudiolab_MainActivity_closeEngine(JNIEnv *env, jobject instance) {

    engine->close();
}

JNIEXPORT void JNICALL
Java_com_denizoncoding_denizonaudiolab_MainActivity_runEngine(JNIEnv *env, jobject instance,
                                                              jboolean onOff) {

    engine->setOn(onOff);
}


}