--- src/bootstrap/bin/rustc.rs.orig	2019-09-23 21:15:52 UTC
+++ src/bootstrap/bin/rustc.rs
@@ -270,7 +270,7 @@ fn main() {
             } else if !target.contains("windows") &&
                       !target.contains("wasm32") &&
                       !target.contains("fuchsia") {
-                Some("-Wl,-rpath,$ORIGIN/../lib")
+                Some("-Wl,-z,origin -Wl,-rpath,$ORIGIN/../lib:@PREFIX@/lib:@OPENSSLLIB@ -L@PREFIX@/lib")
             } else {
                 None
             };
