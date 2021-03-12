--- lib/byteorder64.h.orig	2021-03-09 04:32:13 UTC
+++ lib/byteorder64.h
@@ -49,7 +49,7 @@
 
 #if defined(__linux__) || defined(__OpenBSD__)
 #  include <endian.h>
-#elif defined(__FreeBSD__) || defined(__NetBSD__)
+#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
 #  include <sys/endian.h>
 #endif
 
