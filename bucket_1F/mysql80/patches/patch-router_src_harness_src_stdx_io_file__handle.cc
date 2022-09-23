--- router/src/harness/src/stdx/io/file_handle.cc.orig	2022-07-06 21:36:34 UTC
+++ router/src/harness/src/stdx/io/file_handle.cc
@@ -288,7 +288,10 @@ file_handle::current_path() const noexce
 
   return {path_name};
 #else
-#error unsupported OS
+  // don't use this
+  std::string path_name;
+  path_name.resize(1025);
+  return {path_name};
 #endif
 }
 
