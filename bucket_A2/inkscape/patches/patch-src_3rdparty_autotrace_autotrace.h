--- src/3rdparty/autotrace/autotrace.h.orig	2021-01-15 10:04:25 UTC
+++ src/3rdparty/autotrace/autotrace.h
@@ -22,6 +22,7 @@
 #define AUTOTRACE_H
 
 #include <stdio.h>
+#include "types.h"
 
 #ifdef __cplusplus
 extern "C" {
@@ -35,7 +36,6 @@ extern "C" {
  * Typedefs
  * ===================================================================== */
 
-#include "types.h"
 #include "color.h"
 
 /* Third degree is the highest we deal with.  */
