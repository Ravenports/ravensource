--- util.h.orig	2007-12-27 00:51:05 UTC
+++ util.h
@@ -19,7 +19,7 @@
 #  include <config.h>
 #endif
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 #include <sys/endian.h>
 
 #define __BYTE_ORDER            _BYTE_ORDER
