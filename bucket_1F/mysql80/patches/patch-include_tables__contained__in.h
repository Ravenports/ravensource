--- include/tables_contained_in.h.orig	2023-06-22 11:07:42 UTC
+++ include/tables_contained_in.h
@@ -26,9 +26,14 @@
 
 #include <string.h>
 
+#include "my_config.h"
 #include "my_inttypes.h"
 #include "sql/sql_optimizer.h"
 
+#ifndef HAVE_FFSLL
+int ffsll(longlong);
+#endif
+
 #ifdef _MSC_VER
 #include <intrin.h>
 #pragma intrinsic(_BitScanForward64)
