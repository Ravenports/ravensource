--- src/bootstrap/src/core/builder/cargo.rs.orig	2025-09-14 15:05:11 UTC
+++ src/bootstrap/src/core/builder/cargo.rs
@@ -255,12 +255,13 @@ impl Cargo {
                 && !target.contains("xous")
             {
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
 
