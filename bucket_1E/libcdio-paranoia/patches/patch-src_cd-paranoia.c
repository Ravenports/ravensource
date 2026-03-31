--- src/cd-paranoia.c.orig	2024-05-07 09:41:03 UTC
+++ src/cd-paranoia.c
@@ -60,7 +60,7 @@
 #include <fcntl.h>
 #endif
 
-#include "getopt.h"
+#include <getopt.h>
 
 #ifdef HAVE_ERRNO_H
 #include <errno.h>
