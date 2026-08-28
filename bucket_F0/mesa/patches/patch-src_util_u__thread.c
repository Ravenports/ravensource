--- src/util/u_thread.c.orig	2026-08-05 21:14:26 UTC
+++ src/util/u_thread.c
@@ -176,7 +176,7 @@ util_set_thread_affinity(thrd_t thread,
 int64_t
 util_thread_get_time_nano(thrd_t thread)
 {
-#if defined(HAVE_PTHREAD) && !defined(__APPLE__) && !defined(__HAIKU__) && !defined(__managarm__)
+#if defined(HAVE_PTHREAD) && !defined(__APPLE__) && !defined(__HAIKU__) && !defined(__managarm__) && !defined(__sun__)
    struct timespec ts;
    clockid_t cid;
 
