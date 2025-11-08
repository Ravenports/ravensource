--- src/cast_helpers.h.orig	2025-10-14 15:42:42 UTC
+++ src/cast_helpers.h
@@ -16,6 +16,7 @@
 #error "cast_helpers.h file contains private xmlsec definitions and should not be used outside xmlsec or xmlsec-$crypto libraries"
 #endif /* XMLSEC_PRIVATE */
 
+#include <stdint.h>
 #include <limits.h>
 #include <stdint.h>
 #include "errors_helpers.h"
