Avoid GS conflict on older SunOS.

--- base/ttobjs.h.orig	2025-04-29 11:01:29 UTC
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
