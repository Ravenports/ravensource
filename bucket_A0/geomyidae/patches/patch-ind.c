--- ind.c.orig	2025-07-30 07:47:54 UTC
+++ ind.c
@@ -34,6 +34,9 @@
 #include "arg.h"
 #include "ind.h"
 #include "handlr.h"
+#if defined(__sun)
+#include "dprintf.h"
+#endif
 
 /*
  * Be careful, to look at handlerequest(), in case you add any executing
