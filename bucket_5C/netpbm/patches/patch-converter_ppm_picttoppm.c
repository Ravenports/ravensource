--- converter/ppm/picttoppm.c.orig	2026-02-12 03:48:27 UTC
+++ converter/ppm/picttoppm.c
@@ -23,6 +23,7 @@
  */
 
 #define _XOPEN_SOURCE
+#define _NETBSD_SOURCE
 
 #include <unistd.h>
 #include <stdio.h>
