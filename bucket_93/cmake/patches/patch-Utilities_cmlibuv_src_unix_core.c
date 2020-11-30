--- Utilities/cmlibuv/src/unix/core.c.orig	2020-11-24 13:50:26 UTC
+++ Utilities/cmlibuv/src/unix/core.c
@@ -73,7 +73,11 @@ extern char** environ;
 # include <sys/filio.h>
 # include <sys/wait.h>
 # include <sys/param.h>
+# if defined __DragonFly__
+# include <sys/sched.h>
+# else
 # include <sys/cpuset.h>
+# endif
 # if defined(__FreeBSD__)
 #  define uv__accept4 accept4
 # endif
