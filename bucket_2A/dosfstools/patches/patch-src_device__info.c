--- src/device_info.c.orig	2021-01-31 12:49:12 UTC
+++ src/device_info.c
@@ -24,7 +24,9 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <sys/ioctl.h>
+#if !defined(__DragonFly__) && !defined(__FreeBSD__)
 #include <sys/sysmacros.h>
+#endif
 
 #ifdef HAVE_LINUX_LOOP_H
 #include <linux/loop.h>
