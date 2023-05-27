--- nmap.cc.orig	2023-05-09 14:16:46 UTC
+++ nmap.cc
@@ -67,6 +67,7 @@
 #include <shlobj.h>
 #endif
 
+#include <getopt.h>
 #include "nmap.h"
 #include "osscan.h"
 #include "scan_engine.h"
