--- src/mesa/main/macros.h.orig	2020-06-10 18:03:01 UTC
+++ src/mesa/main/macros.h
@@ -38,6 +38,7 @@
 #include "main/glheader.h"
 #include "mesa_private.h"
 
+#undef ALIGN
 
 /**
  * \name Integer / float conversion for colors, normals, etc.
