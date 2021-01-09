--- src/getopt.c.orig	2021-01-09 11:29:27 UTC
+++ src/getopt.c
@@ -36,6 +36,7 @@
 #endif
 
 #include <stdio.h>
+#include <string.h>
 
 /* Comment out all this code if we are using the GNU C Library, and are not
    actually compiling the library itself.  This code is part of the GNU C
