--- date.c.orig	2018-03-09 07:52:42 UTC
+++ date.c
@@ -1,3 +1,8 @@
+#ifdef __sun__
+#define _LARGEFILE64_SOURCE
+#define __EXTENSIONS__
+#include <setjmp.h>
+#endif
 #include <ctype.h>
 #include <stdio.h>
 #include <string.h>
