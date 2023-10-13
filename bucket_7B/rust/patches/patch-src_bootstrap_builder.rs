--- src/bootstrap/builder.rs.orig	2023-10-03 02:52:17 UTC
+++ src/bootstrap/builder.rs
@@ -1637,12 +1637,13 @@ impl<'a> Builder<'a> {
                 Some(format!("-Wl,-rpath,@loader_path/../{libdir}"))
             } else if !target.contains("windows") && !target.contains("aix") {
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
 
