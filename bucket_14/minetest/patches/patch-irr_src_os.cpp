--- irr/src/os.cpp.orig	2024-09-13 16:54:36 UTC
+++ irr/src/os.cpp
@@ -21,7 +21,7 @@
 #define bswap_16(X) OSReadSwapInt16(&X, 0)
 #define bswap_32(X) OSReadSwapInt32(&X, 0)
 #define bswap_64(X) OSReadSwapInt64(&X, 0)
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
 #include <sys/endian.h>
 #define bswap_16(X) bswap16(X)
 #define bswap_32(X) bswap32(X)
