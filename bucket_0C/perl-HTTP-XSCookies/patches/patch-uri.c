--- uri.c.orig	2018-03-09 07:51:02 UTC
+++ uri.c
@@ -1,3 +1,8 @@
+#ifdef __sun__
+#define _LARGEFILE64_SOURCE
+#define __EXTENSIONS__
+#include <setjmp.h>
+#endif
 #include <ctype.h>
 #include <string.h>
 #include "uri.h"
