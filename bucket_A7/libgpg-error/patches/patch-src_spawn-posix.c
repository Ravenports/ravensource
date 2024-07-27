--- src/spawn-posix.c.orig	2024-06-19 07:33:41 UTC
+++ src/spawn-posix.c
@@ -55,6 +55,10 @@
 # include <dirent.h>
 #endif /*__linux__ */
 
+#if defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__)
+extern char **environ;
+#endif
+
 #include "gpgrt-int.h"
 
 
