--- os/backtrace.c.orig	2021-10-27 10:47:08 UTC
+++ os/backtrace.c
@@ -29,6 +29,7 @@
 #include "misc.h"
 #include <errno.h>
 #include <string.h>
+#include <unistd.h>
 
 #ifdef HAVE_LIBUNWIND
 
