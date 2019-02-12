# expose getline in FreeBSD's stdio.h
#
--- src/intel/tools/aubinator_error_decode.c.orig	2019-01-31 21:05:07 UTC
+++ src/intel/tools/aubinator_error_decode.c
@@ -22,6 +22,9 @@
  *
  */
 
+#ifdef __FreeBSD__
+#define _WITH_GETLINE
+#endif
 #include <stdbool.h>
 #include <stdio.h>
 #include <stdlib.h>
