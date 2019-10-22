--- src/libunwind/build.rs.orig	2019-08-13 06:27:22 UTC
+++ src/libunwind/build.rs
@@ -27,7 +27,7 @@ fn main() {
     } else if target.contains("solaris") {
         println!("cargo:rustc-link-lib=gcc_s");
     } else if target.contains("dragonfly") {
-        println!("cargo:rustc-link-lib=gcc_pic");
+        println!("cargo:rustc-link-lib=gcc_s");
     } else if target.contains("windows-gnu") {
         println!("cargo:rustc-link-lib=static-nobundle=gcc_eh");
         println!("cargo:rustc-link-lib=static-nobundle=pthread");
