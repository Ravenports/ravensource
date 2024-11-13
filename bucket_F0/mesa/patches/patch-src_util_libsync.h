--- src/util/libsync.h.orig	2024-10-30 18:12:27 UTC
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
