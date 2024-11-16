--- gnu/getopt.c.orig	2014-11-19 21:39:47 UTC
+++ gnu/getopt.c
@@ -40,6 +40,7 @@
 #endif
 
 #include <stdio.h>
+#include <string.h> // for strcmp, strncmp, strlen 
 
 /* Comment out all this code if we are using the GNU C Library, and are not
    actually compiling the library itself.  This code is part of the GNU C
