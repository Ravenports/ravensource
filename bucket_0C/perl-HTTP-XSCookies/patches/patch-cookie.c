--- cookie.c.orig	2018-03-09 06:55:51 UTC
+++ cookie.c
@@ -1,3 +1,8 @@
+#ifdef __sun__
+#define _LARGEFILE64_SOURCE
+#define __EXTENSIONS__
+#include <setjmp.h>
+#endif
 #include <ctype.h>
 #include <memory.h>
 #include <stdio.h>
