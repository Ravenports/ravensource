--- include/impl/byteorder.h.orig	2020-08-31 03:14:09 UTC
+++ include/impl/byteorder.h
@@ -33,6 +33,8 @@
 #	include <ws2tcpip.h>
 #elif defined (__APPLE__)
 #	include <libkern/OSByteOrder.h>
+#elif defined (__FreeBSD__) || defined (__DragonFly__)
+#       include <sys/endian.h>
 #else
 #	include <byteswap.h>
 #endif
@@ -49,6 +51,8 @@ pgm_byteswap16 (uint16_t x) {
 	return _byteswap_ushort (x);
 #elif defined (__APPLE__)
 	return OSSwapInt16 (x);
+#elif defined (__FreeBSD__) || defined (__DragonFly__)
+	return bswap16 (x);
 #else
 	return bswap_16 (x);
 #endif
@@ -61,6 +65,8 @@ pgm_byteswap32 (uint32_t x) {
 	return _byteswap_ulong (x);
 #elif defined (__APPLE__)
 	return OSSwapInt32 (x);
+#elif defined (__FreeBSD__) || defined (__DragonFly__)
+	return bswap32 (x);
 #else
 	return bswap_32 (x);
 #endif
