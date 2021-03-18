--- lib/expr/expr.h.orig	2021-03-16 00:04:01 UTC
+++ lib/expr/expr.h
@@ -24,6 +24,7 @@ extern "C" {
 
 #include <ast/ast.h>
 #include <inttypes.h>
+#include <limits.h>
 
 #undef	RS	/* hp.pa <signal.h> grabs this!! */
 
