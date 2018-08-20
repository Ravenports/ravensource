--- gmem.c.orig	2017-07-13 06:43:21 UTC
+++ gmem.c
@@ -1,3 +1,8 @@
+#ifdef __sun__
+#define _LARGEFILE64_SOURCE
+#define __EXTENSIONS__
+#include <setjmp.h>
+#endif
 #include <stdio.h>
 #include <stdlib.h>
 #include "gmem.h"
