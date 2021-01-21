--- lib/expr/expr.h.orig	2021-01-18 17:47:31 UTC
+++ lib/expr/expr.h
@@ -27,6 +27,7 @@ extern "C" {
 
 #include <ast/ast.h>
 #include <inttypes.h>
+#include <limits.h>
 
 #undef	RS	/* hp.pa <signal.h> grabs this!! */
 
