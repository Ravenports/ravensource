- Use monotonic clock for timeouts

--- src/util/os_time.c.orig	2018-12-13 14:02:21 UTC
+++ src/util/os_time.c
@@ -95,7 +95,7 @@ os_time_get_nano(void)
 void
 os_time_sleep(int64_t usecs)
 {
-#if defined(PIPE_OS_LINUX)
+#if defined(HAVE_CLOCK_NANOSLEEP)
    struct timespec time;
    time.tv_sec = usecs / 1000000;
    time.tv_nsec = (usecs % 1000000) * 1000;
