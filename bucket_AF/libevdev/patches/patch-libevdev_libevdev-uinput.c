--- libevdev/libevdev-uinput.c.orig	2026-10-07 07:11:47 UTC
+++ libevdev/libevdev-uinput.c
@@ -15,6 +15,10 @@
 #include <time.h>
 #include <unistd.h>
 
+#if defined(__NetBSD__)
+#include <sys/ioctl.h>
+#endif
+
 #include "libevdev-int.h"
 #include "libevdev-uinput-int.h"
 #include "libevdev-uinput.h"
