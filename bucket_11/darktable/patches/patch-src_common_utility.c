--- src/common/utility.c.orig	2026-02-04 20:20:09 UTC
+++ src/common/utility.c
@@ -40,6 +40,10 @@
   #include <FileAPI.h>
 #endif
 
+#if defined(__NetBSD__)
+#define uselocale(locale) NULL
+#endif
+
 #include <math.h>
 #include <glib/gi18n.h>
 
