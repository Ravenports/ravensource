--- src/common/utility.c.orig	2025-12-20 17:20:27 UTC
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
 
