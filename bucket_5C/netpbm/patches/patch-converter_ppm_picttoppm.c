--- converter/ppm/picttoppm.c.orig	2025-06-29 03:49:30 UTC
+++ converter/ppm/picttoppm.c
@@ -23,6 +23,7 @@
  */
 
 #define _XOPEN_SOURCE
+#define _NETBSD_SOURCE
 
 #include <unistd.h>
 #include <stdio.h>
