--- common/common.h.orig	2020-08-01 22:27:51 UTC
+++ common/common.h
@@ -7,7 +7,7 @@
  * See the LICENSE file for redistribution information.
  */
 
-#include "/usr/include/db.h"	/* Only include db1. */
+#include <db_185.h> 		/* Only include db1. */
 #include <regex.h>		/* May refer to the bundled regex. */
 
 /*
