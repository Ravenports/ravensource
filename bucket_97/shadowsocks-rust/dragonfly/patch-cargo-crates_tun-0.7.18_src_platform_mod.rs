--- cargo-crates/tun-0.7.19/src/platform/mod.rs.orig	2025-05-12 00:10:42 UTC
+++ cargo-crates/tun-0.7.19/src/platform/mod.rs
@@ -24,9 +24,9 @@ pub(crate) mod linux;
 #[cfg(all(target_os = "linux", not(target_env = "ohos")))]
 pub use self::linux::{Device, PlatformConfig, create};
 
-#[cfg(target_os = "freebsd")]
+#[cfg(any(target_os = "freebsd", target_os = "dragonfly"))]
 pub(crate) mod freebsd;
-#[cfg(target_os = "freebsd")]
+#[cfg(any(target_os = "freebsd", target_os = "dragonfly"))]
 pub use self::freebsd::{Device, PlatformConfig, create};
 
 #[cfg(target_os = "macos")]
