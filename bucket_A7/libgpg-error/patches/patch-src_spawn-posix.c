--- src/spawn-posix.c.orig	2025-11-19 11:08:27 UTC
+++ src/spawn-posix.c
@@ -55,6 +55,10 @@
 # include <sys/stat.h>
 #endif
 
+#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
+extern char **environ;
+#endif
+
 #define _GPGRT_NEED_AFLOCAL 1
 #include "gpgrt-int.h"
 
