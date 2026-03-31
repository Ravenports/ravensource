--- c/detype1/source/detype1.c.orig	2025-12-05 00:32:05 UTC
+++ c/detype1/source/detype1.c
@@ -4,6 +4,7 @@
 #include <stdarg.h>
 #include <string.h>
 #include <stdlib.h>
+#include <unistd.h>
 #include <stdbool.h>
 #ifdef _MSC_VER /* defined by Microsoft Compiler */
 #include <io.h>
@@ -524,7 +525,9 @@ static void usage(void) {
 }
 
 #ifndef _MSC_VER /* Unix */
+#if 0
 extern int getopt(int argc, char **argv, char *optstring);
+#endif
 extern int optind;
 extern char *optarg;
 #else  /* dos */
