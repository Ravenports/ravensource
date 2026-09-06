--- src/bootstrap/src/core/builder/cargo.rs.orig	2026-08-18 19:58:58 UTC
+++ src/bootstrap/src/core/builder/cargo.rs
@@ -314,12 +314,13 @@ impl Cargo {
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
 
@@ -353,7 +354,7 @@ impl Cargo {
                 // Do not enable Zlib compression on:
                 // - Windows, because MSVC/PDB doesn't support it
                 // - macOS, because its linker doesn't know the flag
-                if !self.target.is_windows() && !self.target.is_apple() {
+                if !self.target.is_windows() && !self.target.is_apple() && !target.contains("illumos") && !target.contains("solaris") {
                     // If we link through cc, we need the -Wl prefix.
                     // If we don't, then we must not add it, because the linker wouldn't
                     // understand it.
