--- src/log.c.orig	2025-12-19 07:19:53 UTC
+++ src/log.c
@@ -143,7 +143,7 @@ void open_logbuffer(void) {
         logbuffer_size = physical_mem_bytes * 0.01;
     }
 
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__DragonFly__)
     sasprintf(&shmlogname, "/tmp/i3-log-%d", getpid());
 #else
     sasprintf(&shmlogname, "/i3-log-%d", getpid());
@@ -154,7 +154,7 @@ void open_logbuffer(void) {
         return;
     }
 
-#if defined(__OpenBSD__) || defined(__APPLE__)
+#if defined(__OpenBSD__) || defined(__APPLE__) || defined(__DragonFly__)
     if (ftruncate(logbuffer_shm, logbuffer_size) == -1) {
         fprintf(stderr, "Could not ftruncate SHM segment for the i3 log: %s\n", strerror(errno));
 #else
