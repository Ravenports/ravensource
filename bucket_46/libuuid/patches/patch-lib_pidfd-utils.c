--- lib/pidfd-utils.c.orig	2026-04-01 09:51:16 UTC
+++ lib/pidfd-utils.c
@@ -6,7 +6,11 @@
  */
 #include <stdlib.h>
 #include <sys/stat.h>
+#if defined(__DragonFly__) || defined(__FreeBSD__)
+#include <sys/mount.h>
+#else
 #include <sys/vfs.h>
+#endif
 #include <sys/types.h>
 #include <errno.h>
 #include <err.h>
