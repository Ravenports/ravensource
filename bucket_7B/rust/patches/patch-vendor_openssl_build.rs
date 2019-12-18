--- vendor/openssl/build.rs.orig	2019-11-04 17:34:46 UTC
+++ vendor/openssl/build.rs
@@ -46,6 +46,10 @@ fn main() {
             println!("cargo:rustc-cfg=libressl270");
         }
 
+        if version >= 0x2_07_01_00_0 {
+            println!("cargo:rustc-cfg=libressl271");
+        }
+
         if version >= 0x2_07_03_00_0 {
             println!("cargo:rustc-cfg=libressl273");
         }
@@ -53,5 +57,9 @@ fn main() {
         if version >= 0x2_08_00_00_0 {
             println!("cargo:rustc-cfg=libressl280");
         }
+
+        if version >= 0x2_09_01_00_0 {
+            println!("cargo:rustc-cfg=libressl291");
+        }
     }
 }
