--- include/fluent-bit/flb_endian.h.orig	2022-09-27 03:39:50 UTC
+++ include/fluent-bit/flb_endian.h
@@ -39,7 +39,7 @@
  */
 #if defined(__GLIBC__)
 #include <endian.h>
-#elif defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__)
+#elif defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
 #include <sys/endian.h>
 #elif defined(__APPLE__)
 #include <libkern/OSByteOrder.h>
