Avoid GS conflict on older SunOS.

--- base/ttobjs.h.orig	2023-03-27 06:53:17 UTC
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
