--- cargo-crates/shadowsocks-service-1.23.3/src/local/redir/tcprelay/sys/unix/bsd.rs.orig	2025-05-12 00:10:42 UTC
+++ cargo-crates/shadowsocks-service-1.23.3/src/local/redir/tcprelay/sys/unix/bsd.rs
@@ -19,10 +19,10 @@ use crate::{
 impl TcpListenerRedirExt for TcpListener {
     async fn bind_redir(ty: RedirType, addr: SocketAddr, accept_opts: AcceptOpts) -> io::Result<TcpListener> {
         match ty {
-            #[cfg(any(target_os = "freebsd", target_os = "openbsd", target_os = "macos", target_os = "ios"))]
+            #[cfg(any(target_os = "freebsd", target_os = "openbsd", target_os = "macos", target_os = "ios", target_os = "dragonfly"))]
             RedirType::PacketFilter => {}
 
-            #[cfg(any(target_os = "freebsd", target_os = "macos", target_os = "ios"))]
+            #[cfg(any(target_os = "freebsd", target_os = "macos", target_os = "ios", target_os = "dragonfly"))]
             RedirType::IpFirewall => {}
 
             _ => {
@@ -97,7 +97,7 @@ impl TcpListenerRedirExt for TcpListener
 impl TcpStreamRedirExt for TcpStream {
     fn destination_addr(&self, ty: RedirType) -> io::Result<SocketAddr> {
         match ty {
-            #[cfg(any(target_os = "freebsd", target_os = "macos", target_os = "ios"))]
+            #[cfg(any(target_os = "freebsd", target_os = "macos", target_os = "ios", target_os = "dragonfly"))]
             RedirType::PacketFilter => {
                 use crate::local::redir::sys::bsd_pf::PF;
 
@@ -108,7 +108,7 @@ impl TcpStreamRedirExt for TcpStream {
             }
             #[cfg(target_os = "openbsd")] // in OpenBSD, we can get TCP destination address with getsockname()
             RedirType::PacketFilter => self.local_addr(),
-            #[cfg(any(target_os = "freebsd", target_os = "macos", target_os = "ios"))]
+            #[cfg(any(target_os = "freebsd", target_os = "macos", target_os = "ios", target_os = "dragonfly"))]
             RedirType::IpFirewall => {
                 // ## IPFW
                 //
