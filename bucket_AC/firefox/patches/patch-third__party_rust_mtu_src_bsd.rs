--- third_party/rust/mtu/src/bsd.rs.orig	2025-04-14 12:07:30 UTC
+++ third_party/rust/mtu/src/bsd.rs
@@ -50,7 +50,7 @@ const ALIGN: usize = std::mem::size_of::
 // See https://github.com/Arquivotheca/Solaris-8/blob/2ad1d32f9eeed787c5adb07eb32544276e2e2444/osnet_volume/usr/src/cmd/cmd-inet/usr.sbin/route.c#L238-L239
 const ALIGN: usize = std::mem::size_of::<libc::c_long>();
 
-#[cfg(any(target_os = "macos", target_os = "freebsd", target_os = "openbsd"))]
+#[cfg(any(target_os = "macos", target_os = "freebsd", target_os = "openbsd", target_os = "dragonfly"))]
 asserted_const_with_type!(RTM_ADDRS, i32, RTA_DST, u32);
 
 #[cfg(any(target_os = "netbsd", target_os = "solaris"))]
