--- src/util/libsync.h.orig	2021-09-21 16:54:06 UTC
+++ src/util/libsync.h
@@ -37,6 +37,10 @@
 #include <sys/poll.h>
 #include <unistd.h>
 
+#ifdef __sun__
+#include <sys/ioccom.h>
+#endif
+
 #if defined(__cplusplus)
 extern "C" {
 #endif
