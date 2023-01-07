--- cargo-crates/openssl-src-111.24.0+1.1.1s/src/lib.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/openssl-src-111.24.0+1.1.1s/src/lib.rs
@@ -56,6 +56,7 @@ impl Build {
         if host.contains("dragonfly")
             || host.contains("freebsd")
             || host.contains("openbsd")
+            || host.contains("netbsd")
             || host.contains("solaris")
             || host.contains("illumos")
         {
