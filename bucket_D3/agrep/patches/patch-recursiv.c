--- recursiv.c.orig	2016-10-22 12:40:44 UTC
+++ recursiv.c
@@ -21,6 +21,7 @@
 
 #include "autoconf.h"	/* ../libtemplate/include */
 #include <stdio.h>
+#include <stdlib.h>
 #include <sys/types.h>
 
 #if	ISO_CHAR_SET
@@ -53,7 +54,7 @@
 
 #endif
 
-#ifdef __APPLE__
+#if defined __APPLE__ || defined __DragonFly__ || defined __FreeBSD__
     #include <sys/stat.h>
 #endif
 
