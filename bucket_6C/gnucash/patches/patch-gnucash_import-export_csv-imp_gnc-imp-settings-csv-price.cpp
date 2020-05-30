--- gnucash/import-export/csv-imp/gnc-imp-settings-csv-price.cpp.orig	2020-03-15 19:41:11 UTC
+++ gnucash/import-export/csv-imp/gnc-imp-settings-csv-price.cpp
@@ -28,6 +28,7 @@
 
 #include "gnc-imp-settings-csv.hpp"
 #include "gnc-imp-settings-csv-price.hpp"
+#include <algorithm>
 #include <sstream>
 
 extern "C"
