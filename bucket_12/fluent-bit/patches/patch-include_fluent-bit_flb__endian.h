--- include/fluent-bit/flb_endian.h.orig	2021-04-06 01:57:44 UTC
+++ include/fluent-bit/flb_endian.h
@@ -40,7 +40,7 @@
  */
 #if defined(__GLIBC__)
 #include <endian.h>
-#elif defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__)
+#elif defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
 #include <sys/endian.h>
 #elif defined(__APPLE__)
 #include <libkern/OSByteOrder.h>
