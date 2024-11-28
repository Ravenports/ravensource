--- src/util/libsync.h.orig	2024-11-13 15:28:52 UTC
+++ src/util/libsync.h
@@ -40,6 +40,10 @@
 
 #include "util/detect_os.h"
 
+#ifdef __sun__
+#include <sys/ioccom.h>
+#endif
+
 #if defined(__cplusplus)
 extern "C" {
 #endif
