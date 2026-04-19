Avoid name collision on "extended" with SunOS

--- src/path/splinefit/splinefont.h.orig	2025-12-26 00:35:50 UTC
+++ src/path/splinefit/splinefont.h
@@ -3,6 +3,11 @@
 #ifndef _SEEN_SPLINEFONT_H_
 #define _SEEN_SPLINEFONT_H_
 
+#ifdef __sun
+#include <floatingpoint.h>
+#define extended ink_extended
+#endif
+
 #include <glib.h>
 
 typedef double real;
