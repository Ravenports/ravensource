--- src/intel/isl/isl.h.orig	2020-04-29 22:48:24 UTC
+++ src/intel/isl/isl.h
@@ -46,6 +46,9 @@
 #include "util/macros.h"
 
 #ifdef __cplusplus
+# ifdef __sun__
+# define restrict	__restrict__
+# endif
 extern "C" {
 #endif
 
