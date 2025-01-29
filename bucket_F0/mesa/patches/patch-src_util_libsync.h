--- src/util/libsync.h.orig	2025-01-22 18:12:23 UTC
+++ src/util/libsync.h
@@ -41,6 +41,10 @@
 
 #include "util/detect_os.h"
 
+#ifdef __sun__
+#include <sys/ioccom.h>
+#endif
+
 #if defined(__cplusplus)
 extern "C" {
 #endif
