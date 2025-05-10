--- nmap.cc.orig	2025-02-26 17:44:43 UTC
+++ nmap.cc
@@ -68,6 +68,7 @@
 #include <shlobj.h>
 #endif
 
+#include <getopt.h>
 #include "nmap.h"
 #include "osscan.h"
 #include "scan_engine.h"
