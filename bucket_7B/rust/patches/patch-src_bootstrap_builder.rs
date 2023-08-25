--- src/bootstrap/builder.rs.orig	2023-08-23 19:50:10 UTC
+++ src/bootstrap/builder.rs
@@ -1612,12 +1612,13 @@ impl<'a> Builder<'a> {
                 Some("-Wl,-rpath,@loader_path/../lib")
             } else if !target.contains("windows") && !target.contains("aix") {
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
 
