--- src/runtime/thread.c.orig	2019-01-26 20:47:12 UTC
+++ src/runtime/thread.c
@@ -50,7 +50,7 @@
 
 #ifdef LISP_FEATURE_SB_THREAD
 
-#ifdef LISP_FEATURE_OPENBSD
+#if defined LISP_FEATURE_OPENBSD || defined LISP_FEATURE_FREEBSD || defined LISP_FEATURE_DRAGONFLY
 #include <pthread_np.h>
 #endif
 
@@ -537,7 +537,7 @@ attach_os_thread(init_thread_data *scrib
     stack_addr = pthread_get_stackaddr_np(os) - stack_size;
 #else
     pthread_attr_t attr;
-#ifdef LISP_FEATURE_FREEBSD
+#if defined LISP_FEATURE_FREEBSD || defined LISP_FEATURE_DRAGONFLY
     pthread_attr_get_np(os, &attr);
 #else
     int pthread_getattr_np(pthread_t, pthread_attr_t *);
