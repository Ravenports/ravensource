--- handlr.c.orig	2025-07-30 07:47:54 UTC
+++ handlr.c
@@ -18,6 +18,9 @@
 #include <sys/wait.h>
 #include <errno.h>
 #include <libgen.h>
+#if defined(__sun)
+#include "dprintf.h"
+#endif
 
 #include "ind.h"
 #include "arg.h"
