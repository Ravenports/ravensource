--- src/bootstrap/src/core/builder.rs.orig	2023-12-21 16:55:28 UTC
+++ src/bootstrap/src/core/builder.rs
@@ -1678,12 +1678,13 @@ impl<'a> Builder<'a> {
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
 
