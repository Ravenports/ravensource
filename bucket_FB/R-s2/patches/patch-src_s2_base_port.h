--- src/s2/base/port.h.orig	2025-01-07 11:51:24 UTC
+++ src/s2/base/port.h
@@ -30,7 +30,7 @@
 // -----------------------------------------------------------------------------
 
 // IS_LITTLE_ENDIAN, IS_BIG_ENDIAN
-#if defined(__linux__) || defined(__ANDROID__)
+#if defined(__linux__) || defined(__ANDROID__) || defined(__FreeBSD__) || defined(__DragonFly__)
 #include <endian.h>
 
 #elif defined(__APPLE__)
