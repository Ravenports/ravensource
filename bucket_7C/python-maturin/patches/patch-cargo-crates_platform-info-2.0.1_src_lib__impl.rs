--- cargo-crates/platform-info-2.0.1/src/lib_impl.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/platform-info-2.0.1/src/lib_impl.rs
@@ -29,6 +29,8 @@ pub const HOST_OS_NAME: &str = "FreeBSD"
 pub const HOST_OS_NAME: &str = "NetBSD";
 #[cfg(target_os = "openbsd")]
 pub const HOST_OS_NAME: &str = "OpenBSD";
+#[cfg(target_os = "dragonfly")]
+pub const HOST_OS_NAME: &str = "DragonFly";
 #[cfg(target_vendor = "apple")]
 pub const HOST_OS_NAME: &str = "Darwin";
 #[cfg(target_os = "fuchsia")]
