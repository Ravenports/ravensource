--- src/print_disk_info.c.orig	2024-08-19 16:28:44 UTC
+++ src/print_disk_info.c
@@ -11,7 +11,7 @@
 #if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__APPLE__)
 #include <sys/param.h>
 #include <sys/mount.h>
-#elif defined(__NetBSD__)
+#elif defined(__NetBSD__) || defined(__sun)
 #else
 #include <mntent.h>
 #endif
@@ -135,11 +135,11 @@ void print_disk_info(disk_info_ctx_t *ct
 #if defined(__DragonFly__) || defined(__APPLE__)
     struct statfs buf;
 
-    if (statfs(path, &buf) == -1)
+    if (statfs(ctx->path, &buf) == -1)
         return;
 
     mounted = true;
-#elif defined(__NetBSD__) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__OpenBSD__)
+#elif defined(__NetBSD__) || defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__OpenBSD__) || defined(__sun)
     struct statvfs buf;
 
     if (statvfs(ctx->path, &buf) == -1)
