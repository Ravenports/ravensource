--- lib/unistdio/u16-u16-vasnprintf.c.orig	2024-01-29 00:58:11 UTC
+++ lib/unistdio/u16-u16-vasnprintf.c
@@ -31,6 +31,7 @@
 #endif
 
 #include <config.h>
+#include <string.h>
 #include <alloca.h>
 
 /* Specification.  */
