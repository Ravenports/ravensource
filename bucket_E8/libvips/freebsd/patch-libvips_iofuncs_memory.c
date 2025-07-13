--- libvips/iofuncs/memory.c.orig	2025-07-07 12:54:11 UTC
+++ libvips/iofuncs/memory.c
@@ -70,7 +70,7 @@
 #include <stdarg.h>
 #include <string.h>
 #if defined(HAVE__ALIGNED_MALLOC) || defined(HAVE_MEMALIGN)
-#include <malloc.h>
+#include <sys/malloc.h>
 #endif
 
 #include <vips/vips.h>
