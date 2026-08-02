--- comm/third_party/rust/mtu/src/bsd.rs.orig	2026-07-28 12:51:01 UTC
+++ comm/third_party/rust/mtu/src/bsd.rs
@@ -33,6 +33,7 @@ use static_assertions::{const_assert, co
 )]
 #[cfg_attr(target_os = "macos", path = "bindings/macos.rs")]
 #[cfg_attr(target_os = "freebsd", path = "bindings/freebsd.rs")]
+#[cfg_attr(target_os = "dragonfly", path = "bindings/freebsd.rs")]
 #[cfg_attr(target_os = "netbsd", path = "bindings/netbsd.rs")]
 #[cfg_attr(target_os = "openbsd", path = "bindings/openbsd.rs")]
 #[cfg_attr(target_os = "solaris", path = "bindings/solaris.rs")]
@@ -57,7 +58,7 @@ const ALIGN: usize = size_of::<libc::c_i
 // See https://github.com/Arquivotheca/Solaris-8/blob/2ad1d32f9eeed787c5adb07eb32544276e2e2444/osnet_volume/usr/src/cmd/cmd-inet/usr.sbin/route.c#L238-L239
 const ALIGN: usize = size_of::<libc::c_long>();
 
-#[cfg(any(target_os = "macos", target_os = "freebsd", target_os = "openbsd"))]
+#[cfg(any(target_os = "macos", target_os = "freebsd", target_os = "openbsd", target_os = "dragonfly"))]
 asserted_const_with_type!(RTM_ADDRS, i32, RTA_DST, u32);
 
 #[cfg(any(target_os = "netbsd", target_os = "solaris"))]
