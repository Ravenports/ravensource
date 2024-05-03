--- lib/libpam/openpam_configure.c.orig	2022-10-02 14:45:45 UTC
+++ lib/libpam/openpam_configure.c
@@ -43,6 +43,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <limits.h>	/* for PATH_MAX */
 
 #include <security/pam_appl.h>
 
