--- src/bootstrap/builder.rs.orig	2022-05-18 01:29:36 UTC
+++ src/bootstrap/builder.rs
@@ -1304,12 +1304,13 @@ impl<'a> Builder<'a> {
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
 
