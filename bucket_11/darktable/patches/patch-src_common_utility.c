--- src/common/utility.c.orig	2025-06-15 16:52:40 UTC
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
 
