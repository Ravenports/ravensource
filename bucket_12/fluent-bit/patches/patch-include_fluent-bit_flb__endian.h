_XOPEN_SOURCE is messing up sys/socket.h on NetBSD so remove it.

--- include/fluent-bit/flb_endian.h.orig	2025-03-24 22:35:10 UTC
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
