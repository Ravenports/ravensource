--- src/xlib/v4l.c.orig	2023-01-16 05:08:24 UTC
+++ src/xlib/v4l.c
@@ -16,9 +16,9 @@
 int utox_v4l_fd = -1;
 
 #include <sys/mman.h>
-#if defined(__linux__) || defined(__FreeBSD__) || defined(__kFreeBSD__) || defined(__DragonFly__) // FreeBSD and DragonFlyBSD will have the proper includes after installing v4l_compat
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__DragonFly__) // FreeBSD and DragonFlyBSD will have the proper includes after installing v4l_compat
 #include <linux/videodev2.h>
-#elif defined(__OpenBSD__) || defined(__NetBSD__) // OpenBSD and NetBSD have V4L in base
+#elif defined(__OpenBSD__)  // OpenBSD and NetBSD have V4L in base
 #include <sys/videoio.h>
 #else
 #error "Unsupported platform for V4L"
