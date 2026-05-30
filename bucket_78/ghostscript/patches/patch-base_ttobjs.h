Avoid GS conflict on older SunOS.

--- base/ttobjs.h.orig	2026-05-19 11:20:27 UTC
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
