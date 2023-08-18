--- router/src/harness/src/stdx/io/file_handle.cc.orig	2023-06-21 07:52:10 UTC
+++ router/src/harness/src/stdx/io/file_handle.cc
@@ -285,7 +285,10 @@ file_handle::current_path() const noexce
 
   return {path_name};
 #else
-#error unsupported OS
+  // don't use this
+  std::string path_name;
+  path_name.resize(1025);
+  return {path_name};
 #endif
 }
 
