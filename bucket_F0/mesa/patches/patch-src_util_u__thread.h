--- src/util/u_thread.h.orig	2019-10-24 16:13:04 UTC
+++ src/util/u_thread.h
@@ -71,7 +71,7 @@ static inline void u_thread_setname( con
 #if defined(HAVE_PTHREAD)
 #if DETECT_OS_LINUX || DETECT_OS_CYGWIN || DETECT_OS_SOLARIS
    pthread_setname_np(pthread_self(), name);
-#elif DETECT_OS_FREEBSD || DETECT_OS_OPENBSD
+#elif DETECT_OS_FREEBSD || DETECT_OS_OPENBSD || DETECT_OS_DRAGONFLY
    pthread_set_name_np(pthread_self(), name);
 #elif DETECT_OS_NETBSD
    pthread_setname_np(pthread_self(), "%s", (void *)name);
@@ -149,7 +149,7 @@ util_get_L3_for_pinned_thread(thrd_t thr
 static inline int64_t
 u_thread_get_time_nano(thrd_t thread)
 {
-#if defined(__linux__) && defined(HAVE_PTHREAD)
+#if defined(HAVE_PTHREAD) && !defined(__sun)
    struct timespec ts;
    clockid_t cid;
 
