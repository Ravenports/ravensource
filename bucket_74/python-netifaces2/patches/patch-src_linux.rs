--- src/linux.rs.orig	2024-02-28 21:10:30 UTC
+++ src/linux.rs
@@ -78,12 +78,12 @@ pub fn posix_ifaddresses(if_name: &str)
                     add_to_types_mat(AF_PACKET, mac_addr, name, &mut types_mat, &mut any);
                 }
 
-                #[cfg(not(any(target_os = "ios", target_os = "macos")))]
+                #[cfg(target_os = "linux")]
                 if let Some(net_link) = address.as_netlink_addr() {
                     add_to_types_mat(AF_NETLINK, net_link, name, &mut types_mat, &mut any);
                 }
 
-                #[cfg(not(any(target_os = "ios", target_os = "macos")))]
+                #[cfg(target_os = "linux")]
                 if let Some(vsock_addr) = address.as_vsock_addr() {
                     add_to_types_mat(AF_VSOCK, vsock_addr, name, &mut types_mat, &mut any);
                 }
@@ -92,7 +92,7 @@ pub fn posix_ifaddresses(if_name: &str)
                     add_to_types_mat(AF_INET, &inet_addr.ip(), name, &mut types_mat, &mut any);
                 }
 
-                #[cfg(not(any(target_os = "ios", target_os = "macos")))]
+                #[cfg(target_os = "linux")]
                 if let Some(alg_addr) = address.as_alg_addr() {
                     add_to_types_mat(AF_ALG, alg_addr, name, &mut types_mat, &mut any);
                 }
