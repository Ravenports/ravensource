--- src/librustc_llvm/build.rs.orig	2020-07-31 20:16:28 UTC
+++ src/librustc_llvm/build.rs
@@ -259,20 +259,7 @@ fn main() {
     let llvm_static_stdcpp = env::var_os("LLVM_STATIC_STDCPP");
     let llvm_use_libcxx = env::var_os("LLVM_USE_LIBCXX");
 
-    let stdcppname = if target.contains("openbsd") {
-        if target.contains("sparc64") { "estdc++" } else { "c++" }
-    } else if target.contains("freebsd") {
-        "c++"
-    } else if target.contains("darwin") {
-        "c++"
-    } else if target.contains("netbsd") && llvm_static_stdcpp.is_some() {
-        // NetBSD uses a separate library when relocation is required
-        "stdc++_pic"
-    } else if llvm_use_libcxx.is_some() {
-        "c++"
-    } else {
-        "stdc++"
-    };
+    let stdcppname = "stdc++";
 
     // C++ runtime library
     if !target.contains("msvc") {
