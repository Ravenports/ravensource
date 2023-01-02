--- library/unwind/build.rs.orig	2022-12-12 16:02:12 UTC
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
