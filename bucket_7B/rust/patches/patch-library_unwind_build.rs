--- library/unwind/build.rs.orig	2023-01-10 18:47:33 UTC
+++ library/unwind/build.rs
@@ -36,7 +36,7 @@ fn main() {
     } else if target.contains("illumos") {
         println!("cargo:rustc-link-lib=gcc_s");
     } else if target.contains("dragonfly") {
-        println!("cargo:rustc-link-lib=gcc_pic");
+        println!("cargo:rustc-link-lib=gcc_s");
     } else if target.ends_with("pc-windows-gnu") {
         // This is handled in the target spec with late_link_args_[static|dynamic]
     } else if target.contains("uwp-windows-gnu") {
