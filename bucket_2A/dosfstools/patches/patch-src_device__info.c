--- src/device_info.c.orig	2021-01-31 12:49:12 UTC
+++ src/device_info.c
@@ -24,7 +24,9 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <sys/ioctl.h>
+#if !defined(__DragonFly__) && !defined(__FreeBSD__) && !defined(__NetBSD__)
 #include <sys/sysmacros.h>
+#endif
 
 #ifdef HAVE_LINUX_LOOP_H
 #include <linux/loop.h>
@@ -334,7 +336,11 @@ int is_device_mounted(const char *path)
 #endif
 
 #if HAVE_DECL_GETMNTINFO
+# ifdef __NetBSD__
+    struct statvfs *stat;
+# else
     struct statfs *stat;
+# endif
     int count, i;
 
     count = getmntinfo(&stat, 0);
