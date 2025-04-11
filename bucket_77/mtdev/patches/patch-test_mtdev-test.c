--- test/mtdev-test.c.orig	2020-01-26 14:00:32 UTC
+++ test/mtdev-test.c
@@ -31,6 +31,9 @@
 #include <unistd.h>
 #include <fcntl.h>
 #include <stdint.h>
+#if defined(__NetBSD__)
+#include <sys/ioctl.h>
+#endif
 
 #ifndef input_event_sec
 #define input_event_sec time.tv_sec
