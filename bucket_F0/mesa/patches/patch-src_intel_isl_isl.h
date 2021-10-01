--- src/intel/isl/isl.h.orig	2021-09-29 20:10:17 UTC
+++ src/intel/isl/isl.h
@@ -48,6 +48,9 @@
 #include "util/format/u_format.h"
 
 #ifdef __cplusplus
+# ifdef __sun__
+# define restrict	__restrict__
+# endif
 extern "C" {
 #endif
 
