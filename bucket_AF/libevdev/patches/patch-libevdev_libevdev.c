--- libevdev/libevdev.c.orig	2025-03-24 23:41:55 UTC
+++ libevdev/libevdev.c
@@ -14,6 +14,10 @@
 #include <string.h>
 #include <unistd.h>
 
+#if defined(__NetBSD__)
+#include <sys/ioctl.h>
+#endif
+
 #include "libevdev-int.h"
 #include "libevdev-util.h"
 #include "libevdev.h"
