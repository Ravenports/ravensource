--- spa/plugins/v4l2/v4l2-utils.c.orig	2024-02-02 13:09:07 UTC
+++ spa/plugins/v4l2/v4l2-utils.c
@@ -13,6 +13,10 @@
 
 #include <spa/utils/result.h>
 
+typedef uint32_t __u32;
+typedef int32_t  __s32;
+typedef int64_t  __s64;
+
 static int xioctl(int fd, int request, void *arg)
 {
 	int err;
