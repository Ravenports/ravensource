--- compiler/rustc_llvm/build.rs.orig	2021-02-10 17:36:44 UTC
+++ compiler/rustc_llvm/build.rs
@@ -271,22 +271,7 @@ fn main() {
     }
 
     let llvm_static_stdcpp = tracked_env_var_os("LLVM_STATIC_STDCPP");
-    let llvm_use_libcxx = tracked_env_var_os("LLVM_USE_LIBCXX");
-
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
 
     // RISC-V requires libatomic for sub-word atomic operations
     if target.starts_with("riscv") {
