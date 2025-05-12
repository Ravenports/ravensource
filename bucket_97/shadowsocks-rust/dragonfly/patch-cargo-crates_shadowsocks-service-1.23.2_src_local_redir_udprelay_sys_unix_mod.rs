--- cargo-crates/shadowsocks-service-1.23.3/src/local/redir/udprelay/sys/unix/mod.rs.orig	2025-05-12 00:10:42 UTC
+++ cargo-crates/shadowsocks-service-1.23.3/src/local/redir/udprelay/sys/unix/mod.rs
@@ -7,7 +7,7 @@ cfg_if! {
     } else if #[cfg(target_os = "macos")] {
         mod macos;
         pub use self::macos::*;
-    } else if #[cfg(any(target_os = "freebsd"))] {
+    } else if #[cfg(any(target_os = "freebsd", target_os = "dragonfly"))] {
         mod freebsd;
         pub use self::freebsd::*;
     } else if #[cfg(target_os = "openbsd")] {
