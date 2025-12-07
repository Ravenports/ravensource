--- src/3rdparty/assimp/src/contrib/unzip/ioapi.c.orig	2025-11-13 21:08:45 UTC
+++ src/3rdparty/assimp/src/contrib/unzip/ioapi.c
@@ -14,7 +14,7 @@
         #define _CRT_SECURE_NO_WARNINGS
 #endif
 
-#if defined(__APPLE__) || defined(IOAPI_NO_64) || defined(__HAIKU__) || defined(MINIZIP_FOPEN_NO_64)
+#if !defined(__linux__)
 // In darwin and perhaps other BSD variants off_t is a 64 bit value, hence no need for specific 64 bit functions
 #define FOPEN_FUNC(filename, mode) fopen(filename, mode)
 #define FTELLO_FUNC(stream) ftello(stream)
