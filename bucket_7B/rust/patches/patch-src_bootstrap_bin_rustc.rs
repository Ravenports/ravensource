--- src/bootstrap/bin/rustc.rs.orig	2019-02-28 08:53:34 UTC
+++ src/bootstrap/bin/rustc.rs
@@ -227,7 +227,7 @@ fn main() {
             } else if !target.contains("windows") &&
                       !target.contains("wasm32") &&
                       !target.contains("fuchsia") {
-                Some("-Wl,-rpath,$ORIGIN/../lib")
+                Some("-Wl,-z,origin -Wl,-rpath,$ORIGIN/../lib:@PREFIX@/lib:@OPENSSLLIB@ -L@PREFIX@/lib")
             } else {
                 None
             };
