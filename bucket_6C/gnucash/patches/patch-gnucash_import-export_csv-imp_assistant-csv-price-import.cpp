--- gnucash/import-export/csv-imp/assistant-csv-price-import.cpp.orig	2020-04-11 16:28:19 UTC
+++ gnucash/import-export/csv-imp/assistant-csv-price-import.cpp
@@ -27,6 +27,7 @@
     @author Copyright (c) 2017 Robert Fewell
 */
 
+#include <algorithm>
 #include <guid.hpp>
 
 extern "C"
