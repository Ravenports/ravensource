--- src/bootstrap/src/core/builder/cargo.rs.orig	2026-11-09 22:11:55 UTC
+++ src/bootstrap/src/core/builder/cargo.rs
@@ -360,12 +360,13 @@ impl Cargo {
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
 
@@ -401,6 +402,7 @@ impl Cargo {
                 // - macOS, because its linker doesn't know the flag
                 // - Cygwin, because its linker may not support the flag
                 if !self.target.is_windows() && !self.target.is_apple() && !self.target.is_cygwin()
+                && !target.contains("illumos") && !target.contains("solaris")
                 {
                     // If we link through cc, we need the -Wl prefix.
                     // If we don't, then we must not add it, because the linker wouldn't
