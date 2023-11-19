--- src/bootstrap/builder.rs.orig	2023-11-13 04:10:51 UTC
+++ src/bootstrap/builder.rs
@@ -1645,12 +1645,13 @@ impl<'a> Builder<'a> {
                 && !target.contains("xous")
             {
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
 
