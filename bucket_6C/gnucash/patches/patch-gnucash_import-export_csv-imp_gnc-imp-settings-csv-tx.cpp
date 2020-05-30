--- gnucash/import-export/csv-imp/gnc-imp-settings-csv-tx.cpp.orig	2019-09-14 18:56:03 UTC
+++ gnucash/import-export/csv-imp/gnc-imp-settings-csv-tx.cpp
@@ -28,6 +28,7 @@
 
 #include "gnc-imp-settings-csv.hpp"
 #include "gnc-imp-settings-csv-tx.hpp"
+#include <algorithm>
 #include <sstream>
 
 extern "C"
