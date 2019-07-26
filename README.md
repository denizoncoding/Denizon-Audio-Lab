# Denizon-Audio-Lab
This is an Android application for generating audio tone with oscillators and digital audio processing algorithms.

Some specifications:

o Google's oboe is used for audio engine. The engine provides a simple callback mechanism for synthesizing audio.

o The engine is developed as mono-channel.

o Custom C++ wrapper class wraps C++ object id's(long values) with power of JNI and manages them for controlling C++ objects in Java side.

o The wrapper mechanism also automatize generating Java objects respect to related C++ objects.

o Custom digital audio generating and processing algorithm used.

