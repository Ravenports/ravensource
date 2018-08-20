--- baker.xs.orig	2018-03-10 21:35:15 UTC
+++ baker.xs
@@ -1,4 +1,9 @@
 #define PERL_NO_GET_CONTEXT     /* we want efficiency */
+#ifdef __sun__
+#define _LARGEFILE64_SOURCE
+#define __EXTENSIONS__
+#include <setjmp.h>
+#endif
 #include "EXTERN.h"
 #include "perl.h"
 #include "XSUB.h"
