--- cupsfilters/testfilters.c.orig	2024-10-17 20:58:08 UTC
+++ cupsfilters/testfilters.c
@@ -7,6 +7,7 @@
 #include <signal.h>
 #include <stdio.h>
 #include <string.h>
+#include <sys/stat.h> /* S_IRUSR */
 
 /*
  * 'remove_white_space()' - Remove white spaces from beginning and end of a string
