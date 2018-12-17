--- src/bootstrap/bin/rustc.rs.orig	2018-12-04 23:41:40 UTC
+++ src/bootstrap/bin/rustc.rs
@@ -233,7 +233,7 @@ fn main() {
                 cmd.arg("-Z").arg("osx-rpath-install-name");
                 Some("-Wl,-rpath,@loader_path/../lib")
             } else if !target.contains("windows") && !target.contains("wasm32") {
-                Some("-Wl,-rpath,$ORIGIN/../lib")
+                Some("-Wl,-z,origin -Wl,-rpath,$ORIGIN/../lib:@PREFIX@/lib")
             } else {
                 None
             };
