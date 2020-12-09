--- os/backtrace.c.orig	2020-12-01 16:32:25 UTC
+++ os/backtrace.c
@@ -29,6 +29,7 @@
 #include "misc.h"
 #include <errno.h>
 #include <string.h>
+#include <unistd.h>
 
 #ifdef HAVE_LIBUNWIND
 
