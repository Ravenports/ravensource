--- simdzone/src/generic/endian.h.orig	2024-06-13 10:24:08 UTC
+++ simdzone/src/generic/endian.h
@@ -73,6 +73,8 @@
 #define le32toh(x) OSSwapLittleToHostInt32(x)
 #define le64toh(x) OSSwapLittleToHostInt64(x)
 
+#elif defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
+#include <sys/endian.h>
 #else
 #include <endian.h>
 #endif
