--- src/mesa/main/marshal.h.orig	2020-05-14 16:50:14 UTC
+++ src/mesa/main/marshal.h
@@ -32,6 +32,7 @@
 
 #include "main/glthread.h"
 #include "main/context.h"
+#undef ALIGN
 #include "main/macros.h"
 
 struct marshal_cmd_base
