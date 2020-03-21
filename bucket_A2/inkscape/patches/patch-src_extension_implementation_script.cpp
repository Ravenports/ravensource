--- src/extension/implementation/script.cpp.orig	2019-01-15 04:29:27 UTC
+++ src/extension/implementation/script.cpp
@@ -969,10 +969,8 @@ int Script::execute (const std::list<std
         if(Glib::path_is_absolute(filein))
             argv.push_back(filein);
         else {
-            std::vector<std::string> buildargs;
-            buildargs.push_back(Glib::get_current_dir());
-            buildargs.push_back(filein);
-            argv.push_back(Glib::build_filename(buildargs));
+            std::string ss = Glib::get_current_dir() + "/" + filein;
+            argv.push_back(Glib::build_filename(ss));
         }
     }
 
