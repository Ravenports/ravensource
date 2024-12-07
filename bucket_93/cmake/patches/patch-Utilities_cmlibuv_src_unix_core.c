--- Utilities/cmlibuv/src/unix/core.c.orig	2024-12-05 13:42:47 UTC
+++ Utilities/cmlibuv/src/unix/core.c
@@ -86,6 +86,11 @@ extern char** environ;
 # include <sys/cpuset.h>
 #endif
 
+#if defined(__DragonFly__) || defined(__NetBSD__)
+# include <sys/param.h>
+# include <sys/sched.h>
+#endif
+
 #if defined(__MVS__)
 # include <sys/ioctl.h>
 # include "zos-sys-info.h"
