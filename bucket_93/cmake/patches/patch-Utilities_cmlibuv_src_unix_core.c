--- Utilities/cmlibuv/src/unix/core.c.orig	2022-08-17 16:54:57 UTC
+++ Utilities/cmlibuv/src/unix/core.c
@@ -85,6 +85,11 @@ extern char** environ;
 # include <sys/cpuset.h>
 #endif
 
+#if defined(__DragonFly__) || defined(__NetBSD__)
+# include <sys/param.h>
+# include <sys/sched.h>
+#endif
+
 #if defined(__MVS__)
 #include <sys/ioctl.h>
 #endif
