--- libcork/src/libcork/posix/subprocess.c.orig	2019-07-24 14:01:14 UTC
+++ libcork/src/libcork/posix/subprocess.c
@@ -460,7 +460,7 @@ cork_subprocess_start(struct cork_subpro
 #if defined(__APPLE__)
 #include <pthread.h>
 #define THREAD_YIELD   pthread_yield_np
-#elif defined(__linux__) || defined(BSD) || defined(__FreeBSD_kernel__) || defined(__GNU__) || defined(__CYGWIN__)
+#elif defined(__linux__) || defined(BSD) || defined(__FreeBSD_kernel__) || defined(__GNU__) || defined(__CYGWIN__) || defined(__sun__)
 #include <sched.h>
 #define THREAD_YIELD   sched_yield
 #else
