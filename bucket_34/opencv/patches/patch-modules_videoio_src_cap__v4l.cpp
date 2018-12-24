--- modules/videoio/src/cap_v4l.cpp.orig	2018-12-21 14:31:20 UTC
+++ modules/videoio/src/cap_v4l.cpp
@@ -228,7 +228,9 @@ make & enjoy!
 #include <sys/ioctl.h>
 
 #ifdef HAVE_CAMV4L2
+#ifdef __linux__
 #include <asm/types.h>          /* for videodev2.h */
+#endif
 #include <linux/videodev2.h>
 #endif
 
