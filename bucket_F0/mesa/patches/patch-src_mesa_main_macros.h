--- src/mesa/main/macros.h.orig	2020-06-24 21:50:53 UTC
+++ src/mesa/main/macros.h
@@ -38,6 +38,7 @@
 #include "main/glheader.h"
 #include "mesa_private.h"
 
+#undef ALIGN
 
 /**
  * \name Integer / float conversion for colors, normals, etc.
