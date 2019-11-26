--- generic/tclPort.h.orig	2019-06-17 18:39:57 UTC
+++ generic/tclPort.h
@@ -20,7 +20,7 @@
 #if defined(_WIN32)
 #   include "tclWinPort.h"
 #else
-#   include "tclUnixPort.h"
+#   include "../unix/tclUnixPort.h"
 #endif
 #include "tcl.h"
 
