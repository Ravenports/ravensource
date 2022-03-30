--- Utilities/cmlibuv/src/unix/core.c.orig	2022-03-29 15:02:43 UTC
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
