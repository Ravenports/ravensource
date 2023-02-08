--- dao/ScsiIf-lib.cc.orig	2021-03-15 09:13:15 UTC
+++ dao/ScsiIf-lib.cc
@@ -288,6 +288,12 @@ int ScsiIf::inquiry()
     revision_[i] = 0;
   }
 
+  if (vendor_[0] == 0)
+    strncpy(vendor_, "UNKNOWN", 8);
+
+  if (product_[0] == 0)
+    strncpy(product_, "UNKNOWN", 8);
+
   return 0;
 }
 
