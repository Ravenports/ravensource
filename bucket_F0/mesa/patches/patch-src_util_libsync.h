--- src/util/libsync.h.orig	2022-11-16 23:02:11 UTC
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
