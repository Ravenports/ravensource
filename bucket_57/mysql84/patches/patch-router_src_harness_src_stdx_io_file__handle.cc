--- router/src/harness/src/stdx/io/file_handle.cc.orig	2025-03-31 07:51:10 UTC
+++ router/src/harness/src/stdx/io/file_handle.cc
@@ -284,7 +284,10 @@ file_handle::current_path() const noexce
 
   return {path_name};
 #else
-#error unsupported OS
+  // don't use this
+  std::string path_name;
+  path_name.resize(1025);
+  return {path_name};
 #endif
 }
 
