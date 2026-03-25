--- c/type1/source/type1.c.orig	2025-12-05 00:32:05 UTC
+++ c/type1/source/type1.c
@@ -4,6 +4,7 @@
 #include <ctype.h>
 #include <string.h>
 #include <stdarg.h>
+#include <unistd.h>
 #include <stdlib.h>
 #ifdef _MSC_VER /* defined by Microsoft Compiler */
 #include <fcntl.h>
@@ -504,7 +505,9 @@ static void usage(void) {
 }
 
 #ifndef _MSC_VER /* Unix */
+#if defined(__linux__)
 extern int getopt(int argc, char **argv, char *optstring);
+#endif
 extern int optind;
 extern char *optarg;
 #else  /* dos */
