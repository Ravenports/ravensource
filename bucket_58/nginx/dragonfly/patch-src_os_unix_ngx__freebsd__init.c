--- src/os/unix/ngx_freebsd_init.c.orig	2025-10-07 17:04:07 UTC
+++ src/os/unix/ngx_freebsd_init.c
@@ -162,8 +162,7 @@ ngx_os_specific_init(ngx_log_t *log)
      * to allow an old binary to run correctly on an updated FreeBSD system.
      */
 
-#if (__FreeBSD__ == 4 && __FreeBSD_version >= 460102) \
-    || __FreeBSD_version == 460002 || __FreeBSD_version >= 500039
+#if __FreeBSD_version >= 460102
 
     /* a new syscall without the bug */
 
