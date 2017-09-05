--- src/os/unix/ngx_posix_config.h.orig	2017-08-08 15:00:14 UTC
+++ src/os/unix/ngx_posix_config.h
@@ -145,7 +145,7 @@ typedef struct aiocb  ngx_aiocb_t;
 #define ngx_debug_init()
 
 
-#if (__FreeBSD__) && (__FreeBSD_version < 400017)
+#if 0
 
 #include <sys/param.h>          /* ALIGN() */
 
