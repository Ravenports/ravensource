--- libguile/pthread-threads.h.orig	2015-04-11 20:07:14 UTC
+++ libguile/pthread-threads.h
@@ -27,6 +27,9 @@
 */
 
 #include <pthread.h>
+#if HAVE_PTHREAD_NP_H
+# include <pthread_np.h>
+#endif
 #include <sched.h>
 
 /* Threads 
