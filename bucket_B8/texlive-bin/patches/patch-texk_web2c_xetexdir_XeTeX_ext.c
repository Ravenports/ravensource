--- texk/web2c/xetexdir/XeTeX_ext.c.orig	2020-02-08 21:39:50.773480000 +0100
+++ texk/web2c/xetexdir/XeTeX_ext.c	2020-02-08 21:40:35.807156000 +0100
@@ -38,7 +38,10 @@
 
 #include <w2c/config.h>
 
+#ifndef POPPLER_VERSION
 #include <poppler-config.h>
+#endif
+
 #include <png.h>
 #include <zlib.h>
 #include <graphite2/Font.h>
