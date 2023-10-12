--- utils.c.orig	2023-10-09 09:18:22 UTC
+++ utils.c
@@ -34,6 +34,10 @@
 #include <string.h>
 #include <unistd.h>
 
+#ifdef __DragonFly__
+#include <vfs/ufs/dir.h>
+#endif
+
 #ifdef HAVE_LIBPROCSTAT_H
 #include <sys/sysctl.h>
 #include <sys/queue.h>
