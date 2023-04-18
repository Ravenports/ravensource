--- include/tables_contained_in.h.orig	2023-03-16 17:22:37 UTC
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
