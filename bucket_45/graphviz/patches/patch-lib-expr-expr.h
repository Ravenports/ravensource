--- lib/expr/expr.h.orig	2021-02-13 17:02:13 UTC
+++ lib/expr/expr.h
@@ -26,6 +26,7 @@ extern "C" {
 
 #include <ast/ast.h>
 #include <inttypes.h>
+#include <limits.h>
 
 #undef	RS	/* hp.pa <signal.h> grabs this!! */
 
