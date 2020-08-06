--- sal/osl/unx/thread.cxx.orig	2020-07-29 19:29:17 UTC
+++ sal/osl/unx/thread.cxx
@@ -48,6 +48,14 @@
 #include <sys/syscall.h>
 #endif
 
+#ifdef __DragonFly__
+#define __FreeBSD_kernel__
+#endif
+
+#ifdef __FreeBSD_kernel__
+#include <pthread_np.h>
+#endif
+
 /****************************************************************************
  * @@@ TODO @@@
  *
@@ -568,7 +576,7 @@ void SAL_CALL osl_setThreadName(char con
     if ( 0 != err )
         SAL_WARN("sal.osl", "pthread_setname_np failed with errno " << err);
 #elif defined __FreeBSD_kernel__
-    pthread_setname_np( pthread_self(), name );
+    pthread_set_name_np( pthread_self(), name );
 #elif defined MACOSX || defined IOS
     pthread_setname_np( name );
 #else
