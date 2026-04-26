--- src/include/R.h.orig	2025-03-13 23:02:03 UTC
+++ src/include/R.h
@@ -78,6 +78,10 @@
 #include <R_ext/RS.h>
 /* for R_Calloc, R_Realloc, R_Free, Memcpy, F77_xxxx */
 
+/* Compatibility hack for older Rcpp vs newer R-devel */
+#ifndef R_NamespaceRegistry
+#define R_NamespaceRegistry R_NilValue
+#endif
 
 #ifdef __cplusplus
 extern "C" {
