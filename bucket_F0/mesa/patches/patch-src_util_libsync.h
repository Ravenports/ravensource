--- src/util/libsync.h.orig	2024-04-24 18:00:13 UTC
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
