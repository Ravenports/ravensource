--- cupsfilters/pdftoraster.c.orig	2026-08-11 10:31:11 UTC
+++ cupsfilters/pdftoraster.c
@@ -29,6 +29,7 @@
 #include <cupsfilters/bitmap.h>
 #include <strings.h>
 #include <math.h>
+#include <signal.h>
 #include <unistd.h>
 #include <sys/wait.h>
 #include <fcntl.h>
