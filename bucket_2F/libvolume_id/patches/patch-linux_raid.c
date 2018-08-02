--- linux_raid.c.orig	2007-12-27 01:03:43 UTC
+++ linux_raid.c
@@ -22,7 +22,7 @@
 #include <string.h>
 #include <errno.h>
 #include <ctype.h>
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 #include <sys/endian.h>
 #else
 #include <byteswap.h>
