--- lib/ptrarray.c.orig	2026-11-16 17:30:34 UTC
+++ lib/ptrarray.c
@@ -44,6 +44,7 @@
  */
 
 #include "ptrarray.h"
+#include <string.h>
 #include <memory.h>
 #include "util.h"
 #include "xmalloc.h"
