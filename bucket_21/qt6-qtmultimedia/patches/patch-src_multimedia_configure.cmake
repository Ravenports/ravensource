--- src/multimedia/configure.cmake.orig	2026-09-26 16:30:55 UTC
+++ src/multimedia/configure.cmake
@@ -290,7 +290,7 @@ qt_feature("ffmpeg" PRIVATE
     ENABLE INPUT_ffmpeg STREQUAL 'yes'
     DISABLE INPUT_ffmpeg STREQUAL 'no'
     CONDITION FFmpeg_FOUND
-              AND (APPLE OR WIN32 OR ANDROID OR QNX OR QT_FEATURE_pulseaudio OR QT_FEATURE_pipewire)
+              AND (APPLE OR WIN32 OR ANDROID OR QT_FEATURE_alsa OR QNX OR QT_FEATURE_pulseaudio OR QT_FEATURE_pipewire)
               AND QT_FEATURE_thread
 )
 
