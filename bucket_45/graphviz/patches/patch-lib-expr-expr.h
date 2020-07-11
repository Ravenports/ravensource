--- lib/expr/expr.h.orig	2020-06-29 08:47:18 UTC
+++ lib/expr/expr.h
@@ -27,6 +27,7 @@ extern "C" {
 
 #include <ast.h>
 #include <inttypes.h>
+#include <limits.h>
 
 #undef	RS	/* hp.pa <signal.h> grabs this!! */
 
