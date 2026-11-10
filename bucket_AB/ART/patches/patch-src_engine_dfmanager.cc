--- src/engine/dfmanager.cc.orig	2026-11-10 09:54:54 UTC
+++ src/engine/dfmanager.cc
@@ -100,8 +100,8 @@ double DFInfo::distance(const std::strin
         return INFINITY;
     }
 
-    double dISO = (log(this->iso / 100.) - log(iso / 100.)) / log(2);
-    double dShutter = (log(this->shutter) - log(shutter)) / log(2);
+    double dISO = (log(this->iso / 100.0) - log(iso / 100.0)) / log(2.0);
+    double dShutter = (log(this->shutter) - log(shutter)) / log(2.0);
     return sqrt(dISO * dISO + dShutter * dShutter);
 }
 
