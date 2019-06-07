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
// Created by deniz on 9.04.2019.
//

#include <android/log.h>
#include <jni.h>
#include "DenizonEngine.h"

DenizonEngine::DenizonEngine(int sampleRate) {

    this->sampleRate = sampleRate;

    streamBuilder = new AudioStreamBuilder();

//    streamBuilder->setAudioApi(AudioApi::OpenSLES);

    streamBuilder->setDirection(Direction::Output);
    streamBuilder->setSharingMode(SharingMode::Shared);
    streamBuilder->setPerformanceMode(PerformanceMode::LowLatency);
    streamBuilder->setSampleRate(this->sampleRate);
    streamBuilder->setFormat(AudioFormat::Float);
    streamBuilder->setChannelCount(1);
    streamBuilder->setCallback(this);
    this->sampleRate = streamBuilder->getSampleRate();

}

bool DenizonEngine::init() {

    lastResult = streamBuilder->openStream(&stream);

    if (lastResult != Result::OK) {

        __android_log_print(ANDROID_LOG_ERROR,
                            "DenizonEngine",
                            "Error opening stream %s",
                            convertToText(lastResult));
        return false;
    }

    return true;
}

bool DenizonEngine::start() {

    lastResult = stream->requestStart();

    if (lastResult != Result::OK) {

        __android_log_print(ANDROID_LOG_ERROR,
                            "DenizonEngine",
                            "Error starting stream %s",
                            convertToText(lastResult));

        return false;
    }

    return false;
}

bool DenizonEngine::pause() {

    lastResult = stream->requestPause();

    if (lastResult != Result::OK) {

        __android_log_print(ANDROID_LOG_ERROR,
                            "DenizonEngine",
                            "Error pausing stream %s",
                            convertToText(lastResult));

        return false;
    }

    return true;
}

bool DenizonEngine::stop() {

    lastResult = stream->requestStop();

    if (lastResult != Result::OK) {

        __android_log_print(ANDROID_LOG_ERROR,
                            "DenizonEngine",
                            "Error stopping stream %s",
                            convertToText(lastResult));

        return false;
    }

    return true;
}


bool DenizonEngine::flush() {

    lastResult = stream->requestFlush();

    if (lastResult != Result::OK) {

        __android_log_print(ANDROID_LOG_ERROR,
                            "DenizonEngine",
                            "Error flushing stream %s",
                            convertToText(lastResult));

        return false;
    }

    return true;
}

void DenizonEngine::close() {

    stream->close();
}

DataCallbackResult DenizonEngine::onAudioReady(
        AudioStream *oboeStream,
        void *audioData,
        int32_t numFrames) {

    osc->render(static_cast<float *>(audioData), numFrames);

//    processor->processAll(static_cast<float *>(audioData), numFrames);

    //memset(static_cast<uint8_t *>(audioData), 0, sizeof(float) * numFrames);

    return DataCallbackResult::Continue;
}

void DenizonEngine::setOscillator(Oscillator *osc) {

    this->osc = osc;
}

void DenizonEngine::setProcessor(Processor *proc) {

    this->processor = proc;
}