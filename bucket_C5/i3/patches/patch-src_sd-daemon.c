--- src/sd-daemon.c.orig	2026-02-06 07:30:55 UTC
+++ src/sd-daemon.c
@@ -30,6 +30,10 @@
 
 #include "sd-daemon.h"
 
+#if defined(__sun__)
+#include <fcntl.h>
+#endif
+
 #include <errno.h>
 #include <netinet/in.h>
 #include <stdarg.h>
