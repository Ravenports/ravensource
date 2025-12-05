--- dao/ScsiIf-nt.cc.orig	2025-12-05 11:17:35 UTC
+++ dao/ScsiIf-nt.cc
@@ -263,6 +263,12 @@ int ScsiIf::inquiry()
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
 
