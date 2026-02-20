--- ext/mktags.c.orig	2026-02-20 16:03:30 UTC
+++ ext/mktags.c
@@ -1,5 +1,6 @@
 /* block-level tags for passing html blocks through the blender
  */
+#define __EXTENSIONS__
 #include <stdio.h>
 
 #define __WITHOUT_AMALLOC 1
