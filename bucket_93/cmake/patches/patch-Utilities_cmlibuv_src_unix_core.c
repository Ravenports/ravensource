--- Utilities/cmlibuv/src/unix/core.c.orig	2019-09-04 13:58:03 UTC
+++ Utilities/cmlibuv/src/unix/core.c
@@ -66,7 +66,11 @@
 # include <sys/filio.h>
 # include <sys/wait.h>
 # include <sys/param.h>
+# if defined __DragonFly__
+# include <sys/sched.h>
+# else
 # include <sys/cpuset.h>
+# endif
 # define UV__O_CLOEXEC O_CLOEXEC
 # if defined(__FreeBSD__) && __FreeBSD__ >= 10
 #  define uv__accept4 accept4
