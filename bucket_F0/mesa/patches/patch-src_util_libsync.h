--- src/util/libsync.h.orig	2025-12-04 06:02:48 UTC
+++ src/util/libsync.h
@@ -42,6 +42,10 @@
 #include "util/detect_os.h"
 #include "util/os_file.h"
 
+#ifdef __sun__
+#include <sys/ioccom.h>
+#endif
+
 #if defined(__cplusplus)
 extern "C" {
 #endif
