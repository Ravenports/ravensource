--- src/av/audio.h.orig	2019-11-30 00:01:48 UTC
+++ src/av/audio.h
@@ -5,7 +5,11 @@
 #include <stdint.h>
 #include <stdbool.h>
 
-typedef struct ALCdevice_struct ALCdevice;
+#ifdef __APPLE__
+#include <OpenAL/alc.h>
+#else
+#include <AL/alc.h>
+#endif
 
 extern bool utox_audio_thread_init;
 
