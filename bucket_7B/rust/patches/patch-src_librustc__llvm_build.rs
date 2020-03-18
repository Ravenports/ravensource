--- src/librustc_llvm/build.rs.orig	2020-02-24 22:45:57 UTC
+++ src/librustc_llvm/build.rs
@@ -259,10 +259,6 @@ fn main() {
         } else {
             "c++"
         }
-    } else if target.contains("freebsd") {
-        "c++"
-    } else if target.contains("darwin") {
-        "c++"
     } else if target.contains("netbsd") && llvm_static_stdcpp.is_some() {
         // NetBSD uses a separate library when relocation is required
         "stdc++_pic"
