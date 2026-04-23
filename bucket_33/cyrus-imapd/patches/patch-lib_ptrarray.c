--- lib/ptrarray.c.orig	2026-03-29 22:54:00 UTC
+++ lib/ptrarray.c
@@ -44,6 +44,7 @@
  */
 
 #include "ptrarray.h"
+#include <string.h>
 #include <memory.h>
 #include "util.h"
 #include "xmalloc.h"
