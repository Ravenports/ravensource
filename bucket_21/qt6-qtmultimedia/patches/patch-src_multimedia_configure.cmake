--- src/multimedia/configure.cmake.orig	2025-10-15 11:28:20.077549000 +0200
+++ src/multimedia/configure.cmake	2025-10-15 11:28:55.098077000 +0200
@@ -129,7 +129,7 @@
     ENABLE INPUT_ffmpeg STREQUAL 'yes'
     DISABLE INPUT_ffmpeg STREQUAL 'no'
     CONDITION FFmpeg_FOUND
-              AND (APPLE OR WIN32 OR ANDROID OR QNX OR QT_FEATURE_pulseaudio)
+              AND (APPLE OR WIN32 OR ANDROID OR QNX OR QT_FEATURE_alsa OR QT_FEATURE_pulseaudio)
               AND QT_FEATURE_thread
 )
 qt_feature("pipewire" PRIVATE
