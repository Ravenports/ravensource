--- src/s2/base/port.h.orig	2025-01-07 11:51:24 UTC
+++ src/s2/base/port.h
@@ -30,9 +30,22 @@
 // -----------------------------------------------------------------------------
 
 // IS_LITTLE_ENDIAN, IS_BIG_ENDIAN
-#if defined(__linux__) || defined(__ANDROID__)
+#if defined(__MidnightBSD__)
+#include <sys/endian.h>
+#define __BYTE_ORDER _BYTE_ORDER
+#define __LITTLE_ENDIAN _LITTLE_ENDIAN
+#define __BIG_ENDIAN _BIG_ENDIAN
+ 
+#elif defined(__linux__) || defined(__ANDROID__) || defined(__FreeBSD__) || defined(__DragonFly__)
 #include <endian.h>
 
+#elif defined(__NetBSD__)
+
+#include <endian.h>
+#define __BYTE_ORDER _BYTE_ORDER
+#define __LITTLE_ENDIAN _LITTLE_ENDIAN
+#define __BIG_ENDIAN _BIG_ENDIAN
+
 #elif defined(__APPLE__)
 
 // BIG_ENDIAN
