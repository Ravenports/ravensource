--- src/libunwind/build.rs.orig	2019-07-03 08:00:00 UTC
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
