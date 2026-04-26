--- udev-device.c.orig	2024-09-20 07:46:46 UTC
+++ udev-device.c
@@ -28,6 +28,9 @@
 #ifdef __linux__
 #include <sys/sysmacros.h>
 #endif
+#ifdef __sun__
+#include <sys/mkdev.h>
+#endif
 
 #include <stdarg.h>
 #include <stddef.h>
