--- src/bootstrap/builder.rs.orig	2019-11-04 15:45:21 UTC
+++ src/bootstrap/builder.rs
@@ -971,12 +971,13 @@ impl<'a> Builder<'a> {
             } else if !target.contains("windows") &&
                       !target.contains("wasm32") &&
                       !target.contains("fuchsia") {
-                Some("-Wl,-rpath,$ORIGIN/../lib")
+                Some("-Wl,-rpath,$ORIGIN/../lib:@PREFIX@/lib:@OPENSSLLIB@")
             } else {
                 None
             };
             if let Some(rpath) = rpath {
-                rustflags.arg(&format!("-Clink-args={}", rpath));
+                rustflags.arg(&format!("-Clink-arg={}", rpath));
+                rustflags.arg(&format!("-Clink-arg={}", "-L@PREFIX@/lib"));
             }
         }
 
