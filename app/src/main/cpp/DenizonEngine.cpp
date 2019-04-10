//
// Created by deniz on 9.04.2019.
//

#include <android/log.h>
#include "DenizonEngine.h"

DenizonEngine::DenizonEngine(int sampleRate) {

    this->sampleRate = sampleRate;

    streamBuilder = new AudioStreamBuilder();

    streamBuilder->setDirection(Direction::Output);
    streamBuilder->setSharingMode(SharingMode::Shared);
    streamBuilder->setSampleRate(this->sampleRate);
    streamBuilder->setFormat(AudioFormat::Float);
    streamBuilder->setPerformanceMode(PerformanceMode::LowLatency);

}

bool DenizonEngine::init() {

    lastResult = streamBuilder->openStream(&stream);

    if (lastResult != Result::OK) {

        __android_log_print(ANDROID_LOG_ERROR,
                            "DenizonEngine",
                            "Error opening stream %s",
                            convertToText(lastResult));

        isInitialized = false;
    }

    isInitialized = true;

    return isInitialized;
}

bool DenizonEngine::start() {

    lastResult = stream->requestStart();

    if (lastResult != Result::OK) {

        __android_log_print(ANDROID_LOG_ERROR,
                            "DenizonEngine",
                            "Error starting stream %s",
                            convertToText(lastResult));

        isStarted = false;

    }

    isStarted = false;

    return isStarted;
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

    isStarted = false;

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

    isInitialized = false;

    isStarted = false;

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

    isInitialized = false;

    isStarted = false;

    return true;
}

void DenizonEngine::close() {

    stream->close();
}
