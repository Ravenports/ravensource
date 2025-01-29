--- src/util/u_thread.h.orig	2025-01-22 18:12:23 UTC
+++ src/util/u_thread.h
@@ -50,7 +50,7 @@
  * but not with __thread
  */
 #define __THREAD_INITIAL_EXEC __thread
-#elif defined(__GLIBC__)
+#elif defined(__GLIBC__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__MidnightBSD__)
 #define __THREAD_INITIAL_EXEC thread_local __attribute__((tls_model("initial-exec")))
 #define REALLY_INITIAL_EXEC
 #else
