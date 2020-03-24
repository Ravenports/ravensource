--- texk/web2c/pdftexdir/utils.c.orig	2020-02-08 21:37:34.474115000 +0100
+++ texk/web2c/pdftexdir/utils.c	2020-02-08 21:38:06.445787000 +0100
@@ -33,7 +33,6 @@
 #include "ptexlib.h"
 #include <png.h>
 #ifdef POPPLER_VERSION
-#include <poppler-config.h>
 #define xpdfVersion POPPLER_VERSION
 #define xpdfString "poppler"
 #else
