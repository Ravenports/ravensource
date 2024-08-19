--- spa/plugins/v4l2/v4l2-utils.c.orig	2024-07-31 10:02:24 UTC
+++ spa/plugins/v4l2/v4l2-utils.c
@@ -15,6 +15,10 @@
 #include <spa/utils/cleanup.h>
 #include <spa/utils/result.h>
 
+typedef uint32_t __u32;
+typedef int32_t  __s32;
+typedef int64_t  __s64;
+
 static int xioctl(int fd, int request, void *arg)
 {
 	int err;
