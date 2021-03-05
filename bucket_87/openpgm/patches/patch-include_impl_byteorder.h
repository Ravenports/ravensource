--- include/impl/byteorder.h.orig	2020-08-31 03:14:09 UTC
+++ include/impl/byteorder.h
@@ -33,6 +33,10 @@
 #	include <ws2tcpip.h>
 #elif defined (__APPLE__)
 #	include <libkern/OSByteOrder.h>
+#elif defined (__FreeBSD__) || defined (__DragonFly__)
+#       include <sys/endian.h>
+#elif defined (__sun)
+#       include <sys/byteorder.h>
 #else
 #	include <byteswap.h>
 #endif
@@ -49,6 +53,10 @@ pgm_byteswap16 (uint16_t x) {
 	return _byteswap_ushort (x);
 #elif defined (__APPLE__)
 	return OSSwapInt16 (x);
+#elif defined (__FreeBSD__) || defined (__DragonFly__)
+	return bswap16 (x);
+#elif defined (__sun)
+	return BSWAP_16 (x);
 #else
 	return bswap_16 (x);
 #endif
@@ -61,6 +69,10 @@ pgm_byteswap32 (uint32_t x) {
 	return _byteswap_ulong (x);
 #elif defined (__APPLE__)
 	return OSSwapInt32 (x);
+#elif defined (__FreeBSD__) || defined (__DragonFly__)
+	return bswap32 (x);
+#elif defined (__sun)
+	return BSWAP_32 (x);
 #else
 	return bswap_32 (x);
 #endif
