--- nmap.cc.orig	2026-10-23 13:39:29 UTC
+++ nmap.cc
@@ -68,6 +68,7 @@
 #include <shlobj.h>
 #endif
 
+#include <getopt.h>
 #include "nmap.h"
 #include "osscan.h"
 #include "scan_engine.h"
