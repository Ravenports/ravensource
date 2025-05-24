--- spa/plugins/v4l2/v4l2-utils.c.orig	2025-05-22 08:59:37 UTC
+++ spa/plugins/v4l2/v4l2-utils.c
@@ -15,6 +15,12 @@
 #include <spa/utils/cleanup.h>
 #include <spa/utils/result.h>
 
+#if !defined(__linux__) 
+typedef uint32_t __u32;
+typedef int32_t  __s32;
+typedef int64_t  __s64;
+#endif
+
 static int xioctl(int fd, int request, void *arg)
 {
 	int err;
