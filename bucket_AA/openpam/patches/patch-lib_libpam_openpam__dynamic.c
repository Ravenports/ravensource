--- lib/libpam/openpam_dynamic.c.orig	2017-04-30 21:34:49 UTC
+++ lib/libpam/openpam_dynamic.c
@@ -48,6 +48,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
+#include <limits.h>	/* for PATH_MAX */
 
 #include <security/pam_appl.h>
 
