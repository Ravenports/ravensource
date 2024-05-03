--- lib/libpam/openpam_dynamic.c.orig	2022-10-02 14:45:45 UTC
+++ lib/libpam/openpam_dynamic.c
@@ -46,6 +46,7 @@
 #include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
+#include <limits.h>	/* for PATH_MAX */
 
 #include <security/pam_appl.h>
 
