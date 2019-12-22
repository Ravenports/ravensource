--- src/bootstrap/builder.rs.orig	2019-12-16 15:38:05 UTC
+++ src/bootstrap/builder.rs
@@ -994,12 +994,13 @@ impl<'a> Builder<'a> {
                       !target.contains("wasm32") &&
                       !target.contains("emscripten") &&
                       !target.contains("fuchsia") {
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
 
