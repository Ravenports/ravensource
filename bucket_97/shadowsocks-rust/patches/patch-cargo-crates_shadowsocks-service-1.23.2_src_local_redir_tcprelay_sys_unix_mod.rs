--- cargo-crates/shadowsocks-service-1.23.2/src/local/redir/tcprelay/sys/unix/mod.rs.orig	2025-04-29 16:52:02 UTC
+++ cargo-crates/shadowsocks-service-1.23.2/src/local/redir/tcprelay/sys/unix/mod.rs
@@ -7,6 +7,7 @@ cfg_if! {
     } else if #[cfg(any(target_os = "macos",
                         target_os = "ios",
                         target_os = "freebsd",
+                        target_os = "dragonfly",
                         target_os = "openbsd"))] {
         mod bsd;
         pub use self::bsd::*;
