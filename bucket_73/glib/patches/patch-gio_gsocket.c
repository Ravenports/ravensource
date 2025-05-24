--- gio/gsocket.c.orig	2025-05-20 16:22:25 UTC
+++ gio/gsocket.c
@@ -58,6 +58,10 @@
 #include <sys/uio.h>
 #endif
 
+#ifdef __sun__
+#define _XPG4_2	1
+#endif
+
 #define GOBJECT_COMPILATION
 #include "gobject/gtype-private.h" /* For _PRELUDE type define */
 #undef GOBJECT_COMPILATION
