--- nmap.cc.orig	2025-05-12 14:15:39 UTC
+++ nmap.cc
@@ -68,6 +68,7 @@
 #include <shlobj.h>
 #endif
 
+#include <getopt.h>
 #include "nmap.h"
 #include "osscan.h"
 #include "scan_engine.h"
