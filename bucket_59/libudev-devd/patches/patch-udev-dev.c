--- udev-dev.c.orig	2024-09-20 07:46:46 UTC
+++ udev-dev.c
@@ -54,6 +54,10 @@
 #endif
 #endif
 
+#if defined (__NetBSD__)
+#include <sys/ioctl.h>
+#endif
+
 #include "udev-global.h"
 
 #ifdef HAVE_LINUX_INPUT_H
