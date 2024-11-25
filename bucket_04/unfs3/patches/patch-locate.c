--- locate.c.orig	2022-10-06 14:33:16 UTC
+++ locate.c
@@ -27,6 +27,7 @@
 #include "nfs.h"
 #include "fh.h"
 #include "daemon.h"
+#include "attr.h"
 
 /*
  * these are the brute-force file searching routines that are used
