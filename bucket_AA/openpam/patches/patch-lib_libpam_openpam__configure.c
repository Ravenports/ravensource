--- lib/libpam/openpam_configure.c.orig	2017-04-30 21:34:49 UTC
+++ lib/libpam/openpam_configure.c
@@ -45,6 +45,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
+#include <limits.h>	/* for PATH_MAX */
 
 #include <security/pam_appl.h>
 
