--- nmap.cc.orig	2026-02-16 22:33:40 UTC
+++ nmap.cc
@@ -68,6 +68,7 @@
 #include <shlobj.h>
 #endif
 
+#include <getopt.h>
 #include "nmap.h"
 #include "osscan.h"
 #include "scan_engine.h"
