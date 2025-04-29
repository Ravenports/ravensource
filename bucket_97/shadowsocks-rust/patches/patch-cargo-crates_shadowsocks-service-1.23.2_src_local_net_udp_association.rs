--- cargo-crates/shadowsocks-service-1.23.2/src/local/net/udp/association.rs.orig	2025-04-29 04:32:32 UTC
+++ cargo-crates/shadowsocks-service-1.23.2/src/local/net/udp/association.rs
@@ -479,6 +479,7 @@ where
             target_os = "watchos",
             target_os = "tvos",
             target_os = "freebsd",
+            target_os = "dragonfly",
             target_os = "windows",
         ));
 
