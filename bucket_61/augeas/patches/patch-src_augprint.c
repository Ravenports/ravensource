--- src/augprint.c.orig	2022-12-07 12:55:55 UTC
+++ src/augprint.c
@@ -69,7 +69,9 @@
 #include <string.h>
 #include <augeas.h>
 #include <errno.h>
+#ifdef __linux__
 #include <malloc.h>
+#endif
 #include <sys/param.h>     /* for MIN() MAX() */
 #include <unistd.h>
 #include "augprint.h"
