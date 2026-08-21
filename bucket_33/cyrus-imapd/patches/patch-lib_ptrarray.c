--- lib/ptrarray.c.orig	2026-07-15 01:04:35 UTC
+++ lib/ptrarray.c
@@ -44,6 +44,7 @@
  */
 
 #include "ptrarray.h"
+#include <string.h>
 #include <memory.h>
 #include "util.h"
 #include "xmalloc.h"
