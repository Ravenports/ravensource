--- src/util/libsync.h.orig	2023-01-11 17:46:41 UTC
+++ src/util/libsync.h
@@ -38,6 +38,10 @@
 #include <unistd.h>
 #include <time.h>
 
+#ifdef __sun__
+#include <sys/ioccom.h>
+#endif
+
 #if defined(__cplusplus)
 extern "C" {
 #endif
