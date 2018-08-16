--- nsd-control.c.orig	2018-06-12 08:16:08 UTC
+++ nsd-control.c
@@ -63,6 +63,10 @@
 #include "tsig.h"
 #include "options.h"
 
+#ifndef AF_LOCAL
+#define AF_LOCAL AF_UNIX
+#endif
+
 /** Give nsd-control usage, and exit (1). */
 static void
 usage()
