--- audio/audio.h.orig	2024-06-06 15:45:53 UTC
+++ audio/audio.h
@@ -26,6 +26,7 @@
 #if defined(__APPLE__)
         #include <sys/syslimits.h>
 #endif
+#include <limits.h>
 
 
 #include "cpu.h"
