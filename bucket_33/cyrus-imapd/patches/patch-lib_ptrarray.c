--- lib/ptrarray.c.orig	2025-06-27 03:40:02 UTC
+++ lib/ptrarray.c
@@ -44,6 +44,7 @@
  */
 
 #include "ptrarray.h"
+#include <string.h>
 #include <memory.h>
 #include "util.h"
 #include "xmalloc.h"
