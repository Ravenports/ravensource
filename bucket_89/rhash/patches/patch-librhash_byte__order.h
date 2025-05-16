--- librhash/byte_order.h.orig	2025-05-13 20:58:34 UTC
+++ librhash/byte_order.h
@@ -18,6 +18,13 @@
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
