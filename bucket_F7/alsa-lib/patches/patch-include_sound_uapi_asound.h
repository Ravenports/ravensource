--- include/sound/uapi/asound.h.orig	2026-01-13 07:12:40 UTC
+++ include/sound/uapi/asound.h
@@ -15,6 +15,9 @@
 #include <endian.h>
 #include <sys/ioctl.h>
 #endif
+#if defined(__sun)
+#include <sys/ioccom.h>
+#endif
 
 #include <stdlib.h>
 #include <time.h>
