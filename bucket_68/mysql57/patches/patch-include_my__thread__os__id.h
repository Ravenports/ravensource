--- include/my_thread_os_id.h.orig	2022-08-30 03:50:14 UTC
+++ include/my_thread_os_id.h
@@ -37,6 +37,10 @@
 #include <pthread.h>                /* pthread_self */
 #endif
 
+#ifdef __NetBSD__
+#include <lwp.h>
+#endif
+
 #ifdef HAVE_PTHREAD_GETTHREADID_NP
 #include <pthread_np.h>             /* pthread_getthreadid_np() */
 #endif /* HAVE_PTHREAD_GETTHREADID_NP */
@@ -87,13 +91,21 @@ static inline my_thread_os_id_t my_threa
   /* FreeBSD 10.2 */
   return pthread_getthreadid_np();
 #else
+#ifdef __NetBSD__
+  return (int)_lwp_self();
+#else
 #ifdef HAVE_INTEGER_PTHREAD_SELF
+#  ifdef __DragonFly__
+  return syscall(SYS_lwp_gettid);
+#  else
   /* Unknown platform, fallback. */
   return pthread_self();
+#  endif
 #else
   /* Feature not available. */
   return 0;
 #endif /* HAVE_INTEGER_PTHREAD_SELF */
+#endif /* __NetBSD__ */
 #endif /* HAVE_PTHREAD_GETTHREADID_NP */
 #endif /* _WIN32 */
 #endif /* HAVE_SYS_GETTID */
