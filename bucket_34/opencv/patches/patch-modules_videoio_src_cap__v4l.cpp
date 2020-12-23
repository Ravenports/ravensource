--- modules/videoio/src/cap_v4l.cpp.orig	2020-12-21 20:01:38 UTC
+++ modules/videoio/src/cap_v4l.cpp
@@ -231,7 +231,9 @@ make & enjoy!
 #include <poll.h>
 
 #ifdef HAVE_CAMV4L2
+#ifdef __linux__
 #include <asm/types.h>          /* for videodev2.h */
+#endif
 #include <linux/videodev2.h>
 #endif
 
