--- libvips/iofuncs/memory.c.orig	2023-12-21 14:37:04.304915000 +0100
+++ libvips/iofuncs/memory.c	2023-12-21 14:37:32.931439000 +0100
@@ -70,7 +70,7 @@
 #include <stdarg.h>
 #include <string.h>
 #if defined(HAVE__ALIGNED_MALLOC) || defined(HAVE_MEMALIGN)
-#include <malloc.h>
+#include <sys/malloc.h>
 #endif
 
 #include <vips/vips.h>
