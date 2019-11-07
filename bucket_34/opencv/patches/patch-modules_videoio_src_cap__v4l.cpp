--- modules/videoio/src/cap_v4l.cpp.orig	2019-10-09 22:53:14 UTC
+++ modules/videoio/src/cap_v4l.cpp
@@ -229,7 +229,9 @@ make & enjoy!
 #include <limits>
 
 #ifdef HAVE_CAMV4L2
+#ifdef __linux__
 #include <asm/types.h>          /* for videodev2.h */
+#endif
 #include <linux/videodev2.h>
 #endif
 
