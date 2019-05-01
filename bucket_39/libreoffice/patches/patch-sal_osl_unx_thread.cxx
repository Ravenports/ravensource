osl_thread_priority_init_Impl() tries to assign values to variables
declared as const on platforms not excluded by NO_PTHREAD_PRIORITY.
This includes FreeBSD.  This is https://gerrit.libreoffice.org/69603
upstream, and this comment and the relevant parts of this patch can
be removed if/when that is merged.

--- sal/osl/unx/thread.cxx.orig	2019-04-10 10:10:51 UTC
+++ sal/osl/unx/thread.cxx
@@ -46,6 +46,14 @@
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
@@ -88,11 +96,19 @@ typedef struct osl_thread_impl_st
 
 struct osl_thread_priority_st
 {
+#ifndef NO_PTHREAD_PRIORITY
+    int m_Highest;
+    int m_Above_Normal;
+    int m_Normal;
+    int m_Below_Normal;
+    int m_Lowest;
+#else
     int const m_Highest;
     int const m_Above_Normal;
     int const m_Normal;
     int const m_Below_Normal;
     int const m_Lowest;
+#endif /* NO_PTHREAD_PRIORITY */
 };
 
 #define OSL_THREAD_PRIORITY_INITIALIZER { 127, 96, 64, 32, 0 }
@@ -110,7 +126,11 @@ static void osl_thread_textencoding_init
 struct osl_thread_global_st
 {
     pthread_once_t                    m_once;
+#ifndef NO_PTHREAD_PRIORITY
+    struct osl_thread_priority_st     m_priority;
+#else
     struct osl_thread_priority_st const m_priority;
+#endif /* NO_PTHREAD_PRIORITY */
     struct osl_thread_textencoding_st m_textencoding;
 };
 
@@ -545,7 +565,7 @@ void SAL_CALL osl_setThreadName(char con
     if ( 0 != err )
         SAL_WARN("sal.osl", "pthread_setname_np failed with errno " << err);
 #elif defined __FreeBSD_kernel__
-    pthread_setname_np( pthread_self(), name );
+    pthread_set_name_np( pthread_self(), name );
 #elif defined MACOSX || defined IOS
     pthread_setname_np( name );
 #else
