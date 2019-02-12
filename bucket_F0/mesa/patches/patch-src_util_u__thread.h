- Implement setting thread name
- Use monotonic clock for timeouts

--- src/util/u_thread.h.orig	2018-12-13 14:02:21 UTC
+++ src/util/u_thread.h
@@ -34,6 +34,10 @@
 
 #ifdef HAVE_PTHREAD
 #include <signal.h>
+#if defined(__DragonFly__) || defined(__FreeBSD__) || defined(__OpenBSD__)
+#include <pthread_np.h>
+#undef ALIGN /* Avoid conflict on FreeBSD in main/macros.h */
+#endif
 #endif
 
 
@@ -65,6 +69,12 @@ static inline void u_thread_setname( con
       (__GLIBC__ >= 3 || (__GLIBC__ == 2 && __GLIBC_MINOR__ >= 12)) && \
       defined(__linux__)
    pthread_setname_np(pthread_self(), name);
+#  elif defined(__sun)
+   (void)name;
+#  elif defined(__DragonFly__) || defined(__FreeBSD__) || defined(__OpenBSD__)
+   pthread_set_name_np(pthread_self(), name);
+#  elif defined(__NetBSD__)
+   pthread_setname_np(pthread_self(), "%s", (void*)name);
 #  endif
 #endif
    (void)name;
@@ -78,7 +88,7 @@ static inline void u_thread_setname( con
 static inline int64_t
 u_thread_get_time_nano(thrd_t thread)
 {
-#if defined(__linux__) && defined(HAVE_PTHREAD)
+#if defined(HAVE_PTHREAD) && !defined(__sun)
    struct timespec ts;
    clockid_t cid;
 
