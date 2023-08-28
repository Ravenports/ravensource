--- libconsolekit/sd-compat.c.orig	2023-08-11 16:26:44 UTC
+++ libconsolekit/sd-compat.c
@@ -38,6 +38,7 @@
 #include <sys/event.h>
 #endif
 
+#include <stdint.h>
 #include <glib.h>
 #include <glib-object.h>
 #include <glib/gstdio.h>
