--- gnucash/import-export/csv-imp/gnc-imp-settings-csv.cpp.orig	2019-09-14 18:56:03 UTC
+++ gnucash/import-export/csv-imp/gnc-imp-settings-csv.cpp
@@ -27,6 +27,7 @@
 */
 
 #include "gnc-imp-settings-csv.hpp"
+#include <algorithm>
 #include <sstream>
 
 extern "C"
