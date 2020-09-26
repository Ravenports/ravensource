Avoid GS conflict on older SunOS.

--- base/ttobjs.h.orig	2020-09-25 12:32:54 UTC
+++ base/ttobjs.h
@@ -43,6 +43,10 @@
 #include "setjmp_.h"
 #include "ttfoutl.h"
 
+#ifdef __sun
+#undef GS
+#endif
+
 #ifdef __cplusplus
   extern "C" {
 #endif
