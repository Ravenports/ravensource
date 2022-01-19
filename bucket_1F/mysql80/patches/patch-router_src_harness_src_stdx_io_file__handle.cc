--- router/src/harness/src/stdx/io/file_handle.cc.orig	2021-12-17 16:07:27 UTC
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
 
