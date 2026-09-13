--- experimental/sktext/include/Types.h.orig	2023-03-17 16:04:02 UTC
+++ experimental/sktext/include/Types.h
@@ -111,14 +111,8 @@ public:
 
     template<typename Visitor>
     void iterate(Visitor visitor) {
-        if (this->leftToRight()) {
-            for (auto index = this->fStart; index < this->fEnd; ++index) {
-                visitor(index);
-            }
-        } else {
-            for (auto index = this->fStart; index < this->fEnd; --index) {
-                visitor(index);
-            }
+       for (auto index = this->fStart; index < this->fEnd; ++index) {
+           visitor(index);
         }
     }
 
