--- cargo-crates/shadowsocks-service-1.23.3/src/local/redir/sys/unix/mod.rs.orig	2025-05-12 00:10:42 UTC
+++ cargo-crates/shadowsocks-service-1.23.3/src/local/redir/sys/unix/mod.rs
@@ -3,6 +3,7 @@ use cfg_if::cfg_if;
 cfg_if! {
     if #[cfg(any(target_os = "macos",
                  target_os = "ios",
+                 target_os = "dragonfly",
                  target_os = "freebsd"))] {
         pub mod bsd_pf;
     }
@@ -15,7 +16,7 @@ cfg_if! {
         #[allow(dead_code, non_upper_case_globals, non_snake_case, non_camel_case_types)]
         #[allow(clippy::useless_transmute, clippy::too_many_arguments, clippy::unnecessary_cast)]
         mod pfvar;
-    } else if #[cfg(target_os = "freebsd")] {
+    } else if #[cfg(any(target_os = "freebsd", target_os = "dragonfly"))] {
         #[path = "pfvar_bindgen_freebsd.rs"]
         #[allow(dead_code, non_upper_case_globals, non_snake_case, non_camel_case_types)]
         #[allow(clippy::useless_transmute, clippy::too_many_arguments, clippy::unnecessary_cast)]
