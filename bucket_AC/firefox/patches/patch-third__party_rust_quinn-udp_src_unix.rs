--- third_party/rust/quinn-udp/src/unix.rs.orig	2024-12-30 18:31:02 UTC
+++ third_party/rust/quinn-udp/src/unix.rs
@@ -56,12 +56,14 @@ extern "C" {
 // rely on this from the libc crate.
 #[cfg(any(target_os = "openbsd", target_os = "netbsd"))]
 const IPV6_DONTFRAG: libc::c_int = 62;
-#[cfg(not(any(target_os = "openbsd", target_os = "netbsd")))]
+#[cfg(not(any(target_os = "openbsd", target_os = "netbsd", target_os = "dragonfly")))]
 const IPV6_DONTFRAG: libc::c_int = libc::IPV6_DONTFRAG;
+#[cfg(target_os = "dragonfly")]
+const IPV6_DONTFRAG: libc::c_int = 0;
 
-#[cfg(target_os = "freebsd")]
+#[cfg(any(target_os = "freebsd", target_os = "dragonfly"))]
 type IpTosTy = libc::c_uchar;
-#[cfg(not(any(target_os = "freebsd", target_os = "netbsd")))]
+#[cfg(not(any(target_os = "freebsd", target_os = "netbsd", target_os = "dragonfly")))]
 type IpTosTy = libc::c_int;
 
 /// Tokio-compatible UDP socket with some useful specializations.
@@ -114,7 +116,7 @@ impl UdpSocketState {
 
         // mac and ios do not support IP_RECVTOS on dual-stack sockets :(
         // older macos versions also don't have the flag and will error out if we don't ignore it
-        #[cfg(not(any(target_os = "openbsd", target_os = "netbsd", target_os = "solaris")))]
+        #[cfg(not(any(target_os = "openbsd", target_os = "netbsd", target_os = "solaris", target_os = "dragonfly")))]
         if is_ipv4 || !io.only_v6()? {
             if let Err(_err) =
                 set_socket_option(&*io, libc::IPPROTO_IP, libc::IP_RECVTOS, OPTION_ON)
@@ -280,7 +282,7 @@ fn send(
 ) -> io::Result<()> {
     #[allow(unused_mut)] // only mutable on FreeBSD
     let mut encode_src_ip = true;
-    #[cfg(target_os = "freebsd")]
+    #[cfg(any(target_os = "freebsd", target_os = "dragonfly"))]
     {
         let addr = io.local_addr()?;
         let is_ipv4 = addr.family() == libc::AF_INET as libc::sa_family_t;
@@ -445,7 +447,7 @@ fn send(state: &UdpSocketState, io: Sock
     Ok(())
 }
 
-#[cfg(not(any(apple, target_os = "openbsd", target_os = "solaris")))]
+#[cfg(not(any(apple, target_os = "openbsd", target_os = "solaris", target_os = "dragonfly")))]
 fn recv(io: SockRef<'_>, bufs: &mut [IoSliceMut<'_>], meta: &mut [RecvMeta]) -> io::Result<usize> {
     let mut names = [MaybeUninit::<libc::sockaddr_storage>::uninit(); BATCH_SIZE];
     let mut ctrls = [cmsg::Aligned(MaybeUninit::<[u8; CMSG_LEN]>::uninit()); BATCH_SIZE];
@@ -512,7 +514,7 @@ fn recv(io: SockRef<'_>, bufs: &mut [IoS
     Ok(msg_count as usize)
 }
 
-#[cfg(any(target_os = "openbsd", target_os = "netbsd", apple_slow))]
+#[cfg(any(target_os = "openbsd", target_os = "netbsd", target_os = "dragonfly", apple_slow))]
 fn recv(io: SockRef<'_>, bufs: &mut [IoSliceMut<'_>], meta: &mut [RecvMeta]) -> io::Result<usize> {
     let mut name = MaybeUninit::<libc::sockaddr_storage>::uninit();
     let mut ctrl = cmsg::Aligned(MaybeUninit::<[u8; CMSG_LEN]>::uninit());
@@ -677,7 +679,7 @@ fn decode_recv(
                 ecn_bits = cmsg::decode::<u8, libc::cmsghdr>(cmsg);
             },
             // FreeBSD uses IP_RECVTOS here, and we can be liberal because cmsgs are opt-in.
-            #[cfg(not(any(target_os = "openbsd", target_os = "netbsd", target_os = "solaris")))]
+            #[cfg(not(any(target_os = "openbsd", target_os = "netbsd", target_os = "solaris", target_os = "dragonfly")))]
             (libc::IPPROTO_IP, libc::IP_RECVTOS) => unsafe {
                 ecn_bits = cmsg::decode::<u8, libc::cmsghdr>(cmsg);
             },
