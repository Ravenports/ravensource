--- cargo-crates/shadowsocks-service-1.23.2/src/config.rs.orig	2025-04-29 04:32:32 UTC
+++ cargo-crates/shadowsocks-service-1.23.2/src/config.rs
@@ -206,7 +206,7 @@ struct SSConfig {
     outbound_fwmark: Option<u32>,
 
     #[serde(skip_serializing_if = "Option::is_none")]
-    #[cfg(target_os = "freebsd")]
+    #[cfg(any(target_os = "freebsd", target_os = "dragonfly"))]
     outbound_user_cookie: Option<u32>,
 
     #[serde(skip_serializing_if = "Option::is_none")]
@@ -487,6 +487,7 @@ cfg_if! {
             #[cfg(any(
                 target_os = "freebsd",
                 target_os = "openbsd",
+                target_os = "dragonfly",
                 target_os = "macos",
                 target_os = "ios"
             ))]
@@ -497,7 +498,7 @@ cfg_if! {
             /// Supported by FreeBSD, macOS 10.6- (Have been removed completely on macOS 10.10)
             ///
             /// Document: https://www.freebsd.org/doc/handbook/firewalls-ipfw.html
-            #[cfg(any(target_os = "freebsd", target_os = "macos", target_os = "ios"))]
+            #[cfg(any(target_os = "freebsd", target_os = "macos", target_os = "ios", target_os = "dragonfly"))]
             IpFirewall,
         }
 
@@ -527,7 +528,7 @@ cfg_if! {
                         const AVAILABLE_TYPES: &[&str] = &[RedirType::TProxy.name()];
                         AVAILABLE_TYPES
                     }
-                } else if #[cfg(any(target_os = "freebsd"))] {
+                } else if #[cfg(any(target_os = "freebsd", target_os = "dragonfly"))] {
                     /// Default TCP transparent proxy solution on this platform
                     pub fn tcp_default() -> RedirType {
                         RedirType::PacketFilter
@@ -646,12 +647,13 @@ cfg_if! {
                     #[cfg(any(
                         target_os = "freebsd",
                         target_os = "openbsd",
+                        target_os = "dragonfly",
                         target_os = "macos",
                         target_os = "ios"
                     ))]
                     RedirType::PacketFilter => "pf",
 
-                    #[cfg(any(target_os = "freebsd", target_os = "macos", target_os = "ios"))]
+                    #[cfg(any(target_os = "freebsd", target_os = "macos", target_os = "ios", target_os = "dragonfly"))]
                     RedirType::IpFirewall => "ipfw",
                 }
             }
@@ -687,6 +689,7 @@ cfg_if! {
                     #[cfg(any(
                         target_os = "freebsd",
                         target_os = "openbsd",
+                        target_os = "dragonfly",
                         target_os = "macos",
                         target_os = "ios",
                     ))]
@@ -694,6 +697,7 @@ cfg_if! {
 
                     #[cfg(any(
                         target_os = "freebsd",
+                        target_os = "dragonfly",
                         target_os = "macos",
                         target_os = "ios",
                     ))]
@@ -1338,7 +1342,7 @@ pub struct Config {
     #[cfg(any(target_os = "linux", target_os = "android"))]
     pub outbound_fwmark: Option<u32>,
     /// Set `SO_USER_COOKIE` socket option for outbound sockets
-    #[cfg(target_os = "freebsd")]
+    #[cfg(any(target_os = "freebsd", target_os = "dragonfly"))]
     pub outbound_user_cookie: Option<u32>,
     /// Set `SO_BINDTODEVICE` (Linux), `IP_BOUND_IF` (BSD), `IP_UNICAST_IF` (Windows) socket option for outbound sockets
     pub outbound_bind_interface: Option<String>,
@@ -1486,7 +1490,7 @@ impl Config {
 
             #[cfg(any(target_os = "linux", target_os = "android"))]
             outbound_fwmark: None,
-            #[cfg(target_os = "freebsd")]
+            #[cfg(any(target_os = "freebsd", target_os = "dragonfly"))]
             outbound_user_cookie: None,
             outbound_bind_interface: None,
             outbound_bind_addr: None,
@@ -2387,7 +2391,7 @@ impl Config {
         }
 
         // SO_USER_COOKIE
-        #[cfg(target_os = "freebsd")]
+        #[cfg(any(target_os = "freebsd", target_os = "dragonfly"))]
         if let Some(user_cookie) = config.outbound_user_cookie {
             nconfig.outbound_user_cookie = Some(user_cookie);
         }
@@ -3157,7 +3161,7 @@ impl fmt::Display for Config {
             jconf.outbound_fwmark = self.outbound_fwmark;
         }
 
-        #[cfg(target_os = "freebsd")]
+        #[cfg(any(target_os = "freebsd", target_os = "dragonfly"))]
         {
             jconf.outbound_user_cookie = self.outbound_user_cookie;
         }
