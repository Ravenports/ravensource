--- router/src/harness/src/stdx/io/file_handle.cc.orig	2020-06-16 16:31:03 UTC
+++ router/src/harness/src/stdx/io/file_handle.cc
@@ -275,7 +275,10 @@ file_handle::current_path() const noexce
 
   return {path_name};
 #else
-#error unsupported OS
+  // don't use this
+  std::string path_name;
+  path_name.resize(1025);
+  return {path_name};
 #endif
 }
 
