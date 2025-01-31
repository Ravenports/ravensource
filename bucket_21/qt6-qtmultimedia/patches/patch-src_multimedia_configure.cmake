--- src/multimedia/configure.cmake.orig	2025-01-24 11:58:42 UTC
+++ src/multimedia/configure.cmake
@@ -138,7 +138,7 @@ qt_feature("ffmpeg" PRIVATE
     LABEL "FFmpeg"
     ENABLE INPUT_ffmpeg STREQUAL 'yes'
     DISABLE INPUT_ffmpeg STREQUAL 'no'
-    CONDITION FFmpeg_FOUND AND (APPLE OR WIN32 OR ANDROID OR QNX OR QT_FEATURE_pulseaudio)
+    CONDITION FFmpeg_FOUND AND (APPLE OR WIN32 OR ANDROID OR QNX OR QT_FEATURE_alsa OR QT_FEATURE_pulseaudio)
 )
 qt_feature("pipewire" PRIVATE
     LABEL "PipeWire"
