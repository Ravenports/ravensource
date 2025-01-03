--- generic/tclPort.h.orig	2024-12-12 18:07:26 UTC
+++ generic/tclPort.h
@@ -20,7 +20,7 @@
 #if defined(_WIN32)
 #   include "tclWinPort.h"
 #else
-#   include "tclUnixPort.h"
+#   include "../unix/tclUnixPort.h"
 #endif
 #include "tcl.h"
 
