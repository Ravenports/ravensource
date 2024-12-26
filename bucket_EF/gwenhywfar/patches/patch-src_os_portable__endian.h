--- src/os/portable_endian.h.orig	2024-04-21 13:51:43 UTC
+++ src/os/portable_endian.h
@@ -50,7 +50,11 @@
 #	define __LITTLE_ENDIAN LITTLE_ENDIAN
 #	define __PDP_ENDIAN    PDP_ENDIAN
 
-#elif defined(__NetBSD__) || defined(__FreeBSD__) || defined(__DragonFly__)
+#elif defined(__DragonFly__)
+
+#	include <sys/endian.h>
+
+#elif defined(__NetBSD__) || defined(__FreeBSD__)
 
 #	include <sys/endian.h>
 
