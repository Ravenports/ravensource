--- cargo-crates/tun-0.7.19/src/platform/posix/split.rs.orig	2025-05-12 00:10:42 UTC
+++ cargo-crates/tun-0.7.19/src/platform/posix/split.rs
@@ -47,9 +47,9 @@ pub(crate) fn generate_packet_informatio
     const TUN_PROTO_IP4: [u8; PIL] = (libc::AF_INET as u32).to_be_bytes();
 
     // FIXME: Currently, the FreeBSD we test (FreeBSD-14.0-RELEASE) seems to have no PI. Here just a dummy.
-    #[cfg(target_os = "freebsd")]
+    #[cfg(any(target_os = "freebsd", target_os = "dragonfly"))]
     const TUN_PROTO_IP6: [u8; PIL] = 0x86DD_u32.to_be_bytes();
-    #[cfg(target_os = "freebsd")]
+    #[cfg(any(target_os = "freebsd", target_os = "dragonfly"))]
     const TUN_PROTO_IP4: [u8; PIL] = 0x0800_u32.to_be_bytes();
 
     #[cfg(unix)]
