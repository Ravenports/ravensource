--- src/intel/isl/isl.h.orig	2018-12-13 14:02:20 UTC
+++ src/intel/isl/isl.h
@@ -46,6 +46,9 @@
 #include "util/macros.h"
 
 #ifdef __cplusplus
+# ifdef __sun__
+# define restrict	__restrict__
+# endif
 extern "C" {
 #endif
 
