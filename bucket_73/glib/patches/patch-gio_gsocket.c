--- gio/gsocket.c.orig	2018-01-08 20:00:42 UTC
+++ gio/gsocket.c
@@ -52,6 +52,10 @@
 #include <sys/uio.h>
 #endif
 
+#ifdef __sun__
+#define _XPG4_2	1
+#endif
+
 #define GOBJECT_COMPILATION
 #include "gobject/gtype-private.h" /* For _PRELUDE type define */
 #undef GOBJECT_COMPILATION
