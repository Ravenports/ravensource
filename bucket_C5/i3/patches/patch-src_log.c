--- src/log.c.orig	2019-01-27 15:45:19 UTC
+++ src/log.c
@@ -128,7 +128,7 @@ void open_logbuffer(void) {
          * At the moment (2011-12-10), no testcase leads to an i3 log
          * of more than ~ 600 KiB. */
     logbuffer_size = min(physical_mem_bytes * 0.01, shmlog_size);
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__DragonFly__)
     sasprintf(&shmlogname, "/tmp/i3-log-%d", getpid());
 #else
     sasprintf(&shmlogname, "/i3-log-%d", getpid());
@@ -139,7 +139,7 @@ void open_logbuffer(void) {
         return;
     }
 
-#if defined(__OpenBSD__) || defined(__APPLE__)
+#if defined(__OpenBSD__) || defined(__APPLE__) || defined(__DragonFly__)
     if (ftruncate(logbuffer_shm, logbuffer_size) == -1) {
         fprintf(stderr, "Could not ftruncate SHM segment for the i3 log: %s\n", strerror(errno));
 #else
