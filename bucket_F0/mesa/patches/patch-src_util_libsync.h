--- src/util/libsync.h.orig	2026-05-06 19:06:23 UTC
+++ src/util/libsync.h
@@ -43,6 +43,10 @@
 #include "util/detect_os.h"
 #include "util/os_file.h"
 
+#ifdef __sun__
+#include <sys/ioccom.h>
+#endif
+
 #if defined(__cplusplus)
 extern "C" {
 #endif
