--- nmap.cc.orig	2021-07-28 20:52:01 UTC
+++ nmap.cc
@@ -69,6 +69,7 @@
 #include <shlobj.h>
 #endif
 
+#include <getopt.h>
 #include "nmap.h"
 #include "osscan.h"
 #include "scan_engine.h"
