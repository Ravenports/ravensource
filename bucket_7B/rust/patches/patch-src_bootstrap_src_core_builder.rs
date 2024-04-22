--- src/bootstrap/src/core/builder.rs.orig	2024-04-09 17:20:09 UTC
+++ src/bootstrap/src/core/builder.rs
@@ -1684,12 +1684,13 @@ impl<'a> Builder<'a> {
                 Some(format!("-Wl,-rpath,@loader_path/../{libdir}"))
             } else if !target.is_windows() && !target.contains("aix") && !target.contains("xous") {
                 rustflags.arg("-Clink-args=-Wl,-z,origin");
-                Some(format!("-Wl,-rpath,$ORIGIN/../{libdir}"))
+                Some(format!("-Wl,-rpath,$ORIGIN/../{libdir}:@OPENSSLLIB@"))
             } else {
                 None
             };
             if let Some(rpath) = rpath {
-                rustflags.arg(&format!("-Clink-args={rpath}"));
+                rustflags.arg(&format!("-Clink-arg=-Wl,-z,origin"));
+                rustflags.arg(&format!("-Clink-arg={rpath}"));
             }
         }
 
