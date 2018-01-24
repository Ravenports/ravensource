--- librhash/byte_order.h.orig	2018-01-24 16:00:42 UTC
+++ librhash/byte_order.h
@@ -16,6 +16,13 @@
 extern "C" {
 #endif
 
+#ifdef __sun__
+#undef  _LITTLE_ENDIAN
+#define _LITTLE_ENDIAN	1234
+#define _BIG_ENDIAN	4321
+#define _BYTE_ORDER	_LITTLE_ENDIAN
+#endif
+
 /* if x86 compatible cpu */
 #if defined(i386) || defined(__i386__) || defined(__i486__) || \
 	defined(__i586__) || defined(__i686__) || defined(__pentium__) || \
