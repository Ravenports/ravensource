--- cargo-crates/platform-info-1.0.2/src/lib.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/platform-info-1.0.2/src/lib.rs
@@ -76,6 +76,8 @@ const HOST_OS_NAME: &str = "FreeBSD";
 const HOST_OS_NAME: &str = "NetBSD";
 #[cfg(target_os = "openbsd")]
 const HOST_OS_NAME: &str = "OpenBSD";
+#[cfg(target_os = "dragonfly")]
+const HOST_OS_NAME: &str = "DragonFly";
 #[cfg(target_vendor = "apple")]
 const HOST_OS_NAME: &str = "Darwin";
 #[cfg(target_os = "fuchsia")]
