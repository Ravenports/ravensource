--- src/intel/tools/error2aub.c.orig	2019-05-09 20:33:26 UTC
+++ src/intel/tools/error2aub.c
@@ -22,6 +22,9 @@
  *
  */
 
+#ifdef __FreeBSD__
+#define _WITH_GETLINE
+#endif
 #include <assert.h>
 #include <getopt.h>
 #include <inttypes.h>
