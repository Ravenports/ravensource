--- udev-dev.c.orig	2024-09-20 07:46:46 UTC
+++ udev-dev.c
@@ -42,6 +42,24 @@
 #include <string.h>
 #include <unistd.h>
 
+#ifndef _IOC
+#define _IOC(dir,type,nr,size) \
+        ((int)((((unsigned int)(dir)  & 0x3)  << 30) | \
+               (((unsigned int)(type) & 0xFF) << 8)  | \
+               (((unsigned int)(nr)   & 0xFF) << 0)  | \
+               (((unsigned int)(size) & 0x3FFF) << 16)))
+
+#define _IOR(type,nr,size)     _IOC(2UL, (type), (nr), sizeof(size))
+#define _IOW(type,nr,size)     _IOC(1UL, (type), (nr), sizeof(size))
+#endif
+
+/* Linux-specific ioctl direction constants used by input.h */
+#ifndef IOC_OUT
+#define IOC_OUT 2UL
+#endif
+#ifndef IOC_IN
+#define IOC_IN 1UL
+#endif
 #ifdef HAVE_DEV_HID_HIDRAW_H
 #include <dev/hid/hidraw.h>
 #endif
@@ -54,6 +72,10 @@
 #endif
 #endif
 
+#if defined (__NetBSD__)
+#include <sys/ioctl.h>
+#endif
+
 #include "udev-global.h"
 
 #ifdef HAVE_LINUX_INPUT_H
