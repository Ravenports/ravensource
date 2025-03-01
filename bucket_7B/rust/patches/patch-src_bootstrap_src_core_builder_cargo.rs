--- src/bootstrap/src/core/builder/cargo.rs.orig	2025-02-17 18:17:27 UTC
+++ src/bootstrap/src/core/builder/cargo.rs
@@ -238,12 +238,13 @@ impl Cargo {
                 Some(format!("-Wl,-rpath,@loader_path/../{libdir}"))
             } else if !target.is_windows() && !target.contains("aix") && !target.contains("xous") {
                 self.rustflags.arg("-Clink-args=-Wl,-z,origin");
-                Some(format!("-Wl,-rpath,$ORIGIN/../{libdir}"))
+                Some(format!("-Wl,-rpath,$ORIGIN/../{libdir}:@OPENSSLLIB@"))
             } else {
                 None
             };
             if let Some(rpath) = rpath {
-                self.rustflags.arg(&format!("-Clink-args={rpath}"));
+                self.rustflags.arg(&format!("-Clink-arg=-Wl,-z,origin"));
+                self.rustflags.arg(&format!("-Clink-arg={rpath}"));
             }
         }
 
