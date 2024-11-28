--- src/intel/isl/isl.h.orig	2024-11-13 15:28:52 UTC
+++ src/intel/isl/isl.h
@@ -48,6 +48,9 @@
 #include "util/format/u_format.h"
 
 #ifdef __cplusplus
+# ifdef __sun__
+# define restrict	__restrict__
+# endif
 extern "C" {
 #endif
 
