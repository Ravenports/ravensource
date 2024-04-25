--- nmap.cc.orig	2024-02-28 18:46:45 UTC
+++ nmap.cc
@@ -68,6 +68,7 @@
 #include <shlobj.h>
 #endif
 
+#include <getopt.h>
 #include "nmap.h"
 #include "osscan.h"
 #include "scan_engine.h"
