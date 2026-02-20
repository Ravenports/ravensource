--- plugins/python/pyloader.c.orig	2025-10-11 19:15:54 UTC
+++ plugins/python/pyloader.c
@@ -1,3 +1,4 @@
+#include <strings.h>  // for bzero
 #include "uwsgi_python.h"
 
 /* notes
