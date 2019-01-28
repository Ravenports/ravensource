diff --git src/xlib/v4l.c src/xlib/v4l.c
index 3e942a08..d37f19c0 100644
--- src/xlib/v4l.c
+++ src/xlib/v4l.c
@@ -16,9 +16,9 @@
 int utox_v4l_fd = -1;
 
 #include <sys/mman.h>
-#if defined(__linux__) || defined(__FreeBSD__) //FreeBSD will have the proper includes after installing v4l
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__DragonFly__) // FreeBSD and DragonFlyBSD will have the proper includes after installing v4l_compat
 #include <linux/videodev2.h>
-#else //OpenBSD
+#else // OpenBSD and NetBSD have V4L in base
 #include <sys/videoio.h>
 #endif
 
