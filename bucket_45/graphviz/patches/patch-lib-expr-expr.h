--- lib/expr/expr.h.orig	2018-07-24 18:21:09 UTC
+++ lib/expr/expr.h
@@ -27,6 +27,7 @@ extern "C" {
 
 #include <ast.h>
 #include <inttypes.h>
+#include <limits.h>
 
 #undef	RS	/* hp.pa <signal.h> grabs this!! */
 
