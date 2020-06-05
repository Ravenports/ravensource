--- src/librustc_llvm/build.rs.orig	2020-06-01 15:44:16 UTC
+++ src/librustc_llvm/build.rs
@@ -261,10 +261,6 @@ fn main() {
 
     let stdcppname = if target.contains("openbsd") {
         if target.contains("sparc64") { "estdc++" } else { "c++" }
-    } else if target.contains("freebsd") {
-        "c++"
-    } else if target.contains("darwin") {
-        "c++"
     } else if target.contains("netbsd") && llvm_static_stdcpp.is_some() {
         // NetBSD uses a separate library when relocation is required
         "stdc++_pic"
