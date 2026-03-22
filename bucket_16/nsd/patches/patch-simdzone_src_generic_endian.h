--- simdzone/src/generic/endian.h.orig	2026-02-24 09:02:39 UTC
+++ simdzone/src/generic/endian.h
@@ -77,6 +77,8 @@
 #define le32toh(x) OSSwapLittleToHostInt32(x)
 #define le64toh(x) OSSwapLittleToHostInt64(x)
 
+#elif defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
+#include <sys/endian.h>
 #else
 #if HAVE_ENDIAN_H
 #include <endian.h>
