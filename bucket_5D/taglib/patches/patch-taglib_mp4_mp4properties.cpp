--- taglib/mp4/mp4properties.cpp.orig	2025-12-24 14:20:54 UTC
+++ taglib/mp4/mp4properties.cpp
@@ -39,7 +39,7 @@ namespace
   {
     long long totalLength = 0;
     for(const auto &atom : list) {
-      offset_t length = atom->length();
+      TagLib::offset_t length = atom->length();
       if(length == 0)
         return 0; // for safety, see checkValid() in mp4file.cpp
 
