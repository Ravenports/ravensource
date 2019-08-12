--- nmap.cc.orig	2019-07-14 16:54:55 UTC
+++ nmap.cc
@@ -137,6 +137,7 @@
 #include <shlobj.h>
 #endif
 
+#include <getopt.h>
 #include "nmap.h"
 #include "osscan.h"
 #include "scan_engine.h"
