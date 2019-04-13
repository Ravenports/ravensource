--- src/libunwind/build.rs.orig	2019-04-10 18:45:55 UTC
+++ src/libunwind/build.rs
@@ -23,7 +23,7 @@ fn main() {
     } else if target.contains("bitrig") {
         println!("cargo:rustc-link-lib=c++abi");
     } else if target.contains("dragonfly") {
-        println!("cargo:rustc-link-lib=gcc_pic");
+        println!("cargo:rustc-link-lib=gcc_s");
     } else if target.contains("windows-gnu") {
         println!("cargo:rustc-link-lib=static-nobundle=gcc_eh");
         println!("cargo:rustc-link-lib=static-nobundle=pthread");
