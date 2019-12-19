--- src/mesa/main/marshal.h.orig	2019-12-18 19:04:22 UTC
+++ src/mesa/main/marshal.h
@@ -32,6 +32,7 @@
 
 #include "main/glthread.h"
 #include "main/context.h"
+#undef ALIGN
 #include "main/macros.h"
 
 struct marshal_cmd_base
