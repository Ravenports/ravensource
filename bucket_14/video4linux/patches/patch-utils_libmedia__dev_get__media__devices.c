--- utils/libmedia_dev/get_media_devices.c.orig	2014-03-02 09:11:40 UTC
+++ utils/libmedia_dev/get_media_devices.c
@@ -26,6 +26,9 @@
 #include <dirent.h>
 #include <limits.h>
 #include "get_media_devices.h"
+#ifdef __sun__
+#include <sys/sysmacros.h>
+#endif
 
 #define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
 
