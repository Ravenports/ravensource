--- libvips/conversion/composite.cpp.orig	2023-10-22 17:44:51.970733000 +0200
+++ libvips/conversion/composite.cpp	2023-10-22 17:45:27.043783000 +0200
@@ -63,7 +63,7 @@
 #include <math.h>
 
 #if defined(HAVE__ALIGNED_MALLOC) || defined(HAVE_MEMALIGN)
-#include <malloc.h>
+#include <sys/malloc.h>
 #endif
 
 #include <vips/vips.h>
