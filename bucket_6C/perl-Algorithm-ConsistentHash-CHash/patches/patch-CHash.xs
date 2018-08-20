--- CHash.xs.orig	2014-08-12 08:30:04 UTC
+++ CHash.xs
@@ -1,3 +1,8 @@
+#ifdef __sun__
+#define _LARGEFILE64_SOURCE 1
+#define __EXTENSIONS__ 1
+#include <setjmp.h>
+#endif
 #include "EXTERN.h"
 #include "perl.h"
 #include "XSUB.h"
