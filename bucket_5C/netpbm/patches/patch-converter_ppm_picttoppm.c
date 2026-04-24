--- converter/ppm/picttoppm.c.orig	2026-03-31 00:09:30 UTC
+++ converter/ppm/picttoppm.c
@@ -23,6 +23,7 @@
  */
 
 #define _XOPEN_SOURCE
+#define _NETBSD_SOURCE
 
 #include <unistd.h>
 #include <stdio.h>
