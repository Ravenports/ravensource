--- aucat/defs.h.orig	2026-10-15 10:05:00 UTC
+++ aucat/defs.h
@@ -17,6 +17,12 @@
 #ifndef DEFS_H
 #define DEFS_H
 
+#ifdef __sun__
+#define BIG_ENDIAN 4321
+#define LITTLE_ENDIAN 1234
+#define BYTE_ORDER LITTLE_ENDIAN
+#endif
+
 /*
  * limits
  */
