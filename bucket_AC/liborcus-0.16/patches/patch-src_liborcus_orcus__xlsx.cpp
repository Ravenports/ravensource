--- src/liborcus/orcus_xlsx.cpp.orig	2020-09-26 17:56:58 UTC
+++ src/liborcus/orcus_xlsx.cpp
@@ -30,6 +30,7 @@
 #include "ooxml_global.hpp"
 #include "spreadsheet_iface_util.hpp"
 
+#include <limits>
 #include <cstdlib>
 #include <iostream>
 #include <string>
