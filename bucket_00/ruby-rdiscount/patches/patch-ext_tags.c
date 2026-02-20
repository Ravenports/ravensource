--- ext/tags.c.orig	2026-02-20 16:27:33 UTC
+++ ext/tags.c
@@ -1,5 +1,6 @@
 /* block-level tags for passing html blocks through the blender
  */
+#define __EXTENSIONS__
 #include "config.h"
 
 #define __WITHOUT_AMALLOC 1
