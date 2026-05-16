--- Source/ThirdParty/libsysprof-capture/sysprof-collector.c.orig	2026-02-23 14:40:52 UTC
+++ Source/ThirdParty/libsysprof-capture/sysprof-collector.c
@@ -56,6 +56,10 @@
 
 #include "config.h"
 
+#if defined(__sun)
+#define _XPG4_2
+#define __EXTENSIONS__
+#endif
 #include <assert.h>
 #include <errno.h>
 #include <fcntl.h>
