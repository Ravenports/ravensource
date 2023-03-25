--- cargo-crates/openssl-src-111.24.0+1.1.1s/src/lib.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/openssl-src-111.24.0+1.1.1s/src/lib.rs
@@ -52,17 +52,7 @@ impl Build {
     }
 
     fn cmd_make(&self) -> Command {
-        let host = &self.host.as_ref().expect("HOST dir not set")[..];
-        if host.contains("dragonfly")
-            || host.contains("freebsd")
-            || host.contains("openbsd")
-            || host.contains("solaris")
-            || host.contains("illumos")
-        {
-            Command::new("gmake")
-        } else {
-            Command::new("make")
-        }
+        Command::new("gmake")
     }
 
     #[cfg(windows)]
