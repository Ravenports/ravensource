--- src/util/libsync.h.orig	2026-06-18 06:44:14 UTC
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
