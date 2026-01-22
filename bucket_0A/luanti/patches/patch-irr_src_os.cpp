--- irr/src/os.cpp.orig	2026-01-20 17:24:14 UTC
+++ irr/src/os.cpp
@@ -25,7 +25,7 @@
 #define bswap_16(X) OSReadSwapInt16(&X, 0)
 #define bswap_32(X) OSReadSwapInt32(&X, 0)
 #define bswap_64(X) OSReadSwapInt64(&X, 0)
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
 #include <sys/endian.h>
 #define bswap_16(X) bswap16(X)
 #define bswap_32(X) bswap32(X)
