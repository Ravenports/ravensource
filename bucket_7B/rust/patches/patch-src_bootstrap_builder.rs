--- src/bootstrap/builder.rs.orig	2022-02-23 04:07:21 UTC
+++ src/bootstrap/builder.rs
@@ -1186,12 +1186,13 @@ impl<'a> Builder<'a> {
                 Some("-Wl,-rpath,@loader_path/../lib")
             } else if !target.contains("windows") {
                 rustflags.arg("-Clink-args=-Wl,-z,origin");
-                Some("-Wl,-rpath,$ORIGIN/../lib")
+                Some("-Wl,-rpath,$ORIGIN/../lib:@OPENSSLLIB@")
             } else {
                 None
             };
             if let Some(rpath) = rpath {
-                rustflags.arg(&format!("-Clink-args={}", rpath));
+                rustflags.arg(&format!("-Clink-arg={}", "-Wl,-z,origin"));
+                rustflags.arg(&format!("-Clink-arg={}", rpath));
             }
         }
 
