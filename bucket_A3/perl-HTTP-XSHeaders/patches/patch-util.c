--- util.c.orig	2015-12-29 09:01:46 UTC
+++ util.c
@@ -1,4 +1,9 @@
 #define PERL_NO_GET_CONTEXT     /* we want efficiency */
+#ifdef __sun__
+#define _LARGEFILE64_SOURCE
+#define __EXTENSIONS__
+#include <setjmp.h>
+#endif
 #include "EXTERN.h"
 #include "perl.h"
 
