--- cargo-crates/platform-info-2.0.5/src/lib_impl.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/platform-info-2.0.5/src/lib_impl.rs
@@ -46,6 +46,8 @@ const HOST_OS_NAME: &str = if cfg!(all(
     "NetBSD"
 } else if cfg!(target_os = "openbsd") {
     "OpenBSD"
+} else if cfg!(target_os = "dragonfly") {
+    "DragonFly"
 } else if cfg!(target_vendor = "apple") {
     "Darwin"
 } else if cfg!(target_os = "fuchsia") {
