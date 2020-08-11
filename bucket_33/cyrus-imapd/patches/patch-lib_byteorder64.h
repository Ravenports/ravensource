--- lib/byteorder64.h.orig	2019-11-15 03:25:39 UTC
+++ lib/byteorder64.h
@@ -49,7 +49,7 @@
 
 #if defined(__linux__)
 #  include <endian.h>
-#elif defined(__FreeBSD__) || defined(__NetBSD__)
+#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__)
 #  include <sys/endian.h>
 #elif defined(__OpenBSD__)
 #  include <sys/types.h>
