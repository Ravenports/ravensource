--- cargo-crates/tikv-jemalloc-sys-0.7.1+5.3.1-0-g81034ce1f1373e37dc865038e1bc8eeecf559ce8/build.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/tikv-jemalloc-sys-0.7.1+5.3.1-0-g81034ce1f1373e37dc865038e1bc8eeecf559ce8/build.rs
@@ -463,21 +463,7 @@ fn gnu_target(target: &str) -> String {
 }
 
 fn make_cmd(host: &str) -> &'static str {
-    const GMAKE_HOSTS: &[&str] = &[
-        "bitrig",
-        "dragonfly",
-        "freebsd",
-        "netbsd",
-        "openbsd",
-        "chimera-linux",
-    ];
-    if GMAKE_HOSTS.iter().any(|i| host.contains(i)) {
         "gmake"
-    } else if host.contains("windows") {
-        "mingw32-make"
-    } else {
-        "make"
-    }
 }
 
 struct BackgroundThreadSupport {
