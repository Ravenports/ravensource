--- src/util/libsync.h.orig	2021-09-08 21:22:06 UTC
+++ src/util/libsync.h
@@ -36,6 +36,10 @@
 #include <sys/poll.h>
 #include <unistd.h>
 
+#ifdef __sun__
+#include <sys/ioccom.h>
+#endif
+
 #if defined(__cplusplus)
 extern "C" {
 #endif
