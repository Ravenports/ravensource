--- src/common/utility.c.orig	2025-02-08 17:55:20 UTC
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
 
