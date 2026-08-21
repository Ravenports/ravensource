--- src/avrftdi.c.orig	2026-07-11 11:11:28 UTC
+++ src/avrftdi.c
@@ -30,6 +30,9 @@
 #include <unistd.h>
 #include <stdint.h>
 #include <stdarg.h>
+#if defined(__sun)
+#include <alloca.h>
+#endif
 
 #include "avrdude.h"
 #include "libavrdude.h"
