--- src/mesa/main/marshal.h.orig	2020-04-03 10:15:27 UTC
+++ src/mesa/main/marshal.h
@@ -32,6 +32,7 @@
 
 #include "main/glthread.h"
 #include "main/context.h"
+#undef ALIGN
 #include "main/macros.h"
 
 struct marshal_cmd_base
