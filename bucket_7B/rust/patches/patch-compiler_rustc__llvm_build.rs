--- compiler/rustc_llvm/build.rs.orig	2025-09-14 15:05:11 UTC
+++ compiler/rustc_llvm/build.rs
@@ -368,25 +368,7 @@ fn main() {
     }
 
     let llvm_static_stdcpp = tracked_env_var_os("LLVM_STATIC_STDCPP");
-    let llvm_use_libcxx = tracked_env_var_os("LLVM_USE_LIBCXX");
-
-    let stdcppname = if target.contains("openbsd") {
-        if target.contains("sparc64") { "estdc++" } else { "c++" }
-    } else if target.contains("darwin")
-        || target.contains("freebsd")
-        || target.contains("windows-gnullvm")
-        || target.contains("aix")
-        || target.contains("ohos")
-    {
-        "c++"
-    } else if target.contains("netbsd") && llvm_static_stdcpp.is_some() {
-        // NetBSD uses a separate library when relocation is required
-        "stdc++_p"
-    } else if llvm_use_libcxx.is_some() {
-        "c++"
-    } else {
-        "stdc++"
-    };
+    let stdcppname = "stdc++";
 
     // RISC-V GCC erroneously requires libatomic for sub-word
     // atomic operations. Some BSD uses Clang as its system
