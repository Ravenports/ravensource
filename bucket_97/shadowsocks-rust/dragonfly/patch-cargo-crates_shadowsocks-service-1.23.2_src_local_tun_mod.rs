--- cargo-crates/shadowsocks-service-1.23.3/src/local/tun/mod.rs.orig	2025-05-12 00:10:42 UTC
+++ cargo-crates/shadowsocks-service-1.23.3/src/local/tun/mod.rs
@@ -28,6 +28,7 @@ cfg_if! {
                  target_os = "linux",
                  target_os = "android",
                  target_os = "windows",
+                 target_os = "dragonfly",
                  target_os = "freebsd"))] {
         use tun::{
             create_as_async, AsyncDevice, Configuration as TunConfiguration, AbstractDevice, Error as TunError, Layer,
