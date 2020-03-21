--- src/resource-manager.cpp.orig	2019-01-15 04:29:27 UTC
+++ src/resource-manager.cpp
@@ -93,7 +93,13 @@ static std::string convertPathToRelative
                 for ( size_t i = 0; i < baseParts.size(); ++i ) {
                     parts.insert(parts.begin(), "..");
                 }
-                result = Glib::build_filename( parts );
+                std::string ss;
+                for(auto k : parts) {
+                   if(!ss.empty())
+                      ss += "/";
+                   ss += k;
+                } 
+                result = Glib::build_filename(ss);
                 // TODO debug g_message("----> [%s]", result.c_str());
             }
         }
@@ -362,7 +368,13 @@ bool ResourceManagerImpl::searchUpwards(
             std::vector<std::string> combined;
             combined.insert( combined.end(), baseParts.begin(), baseParts.end() );
             combined.insert( combined.end(), current.begin(), current.end() );
-            std::string filepath = Glib::build_filename( combined );
+            std::string ss;
+            for(auto k : parts) {
+               if(!ss.empty())
+                  ss += "/";
+               ss += k;
+            } 
+            std::string filepath = Glib::build_filename(ss);
             exists = Glib::file_test(filepath, Glib::FILE_TEST_EXISTS);
             // TODO debug g_message("            ...[%s] %s", filepath.c_str(), (exists ? "XXX" : ""));
             if ( exists ) {
