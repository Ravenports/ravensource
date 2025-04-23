--- comm/third_party/rust/quinn-udp/src/unix.rs.orig	2025-04-12 05:14:10 UTC
+++ comm/third_party/rust/quinn-udp/src/unix.rs
@@ -55,12 +55,14 @@ extern "C" {
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
@@ -113,7 +115,7 @@ impl UdpSocketState {
 
         // mac and ios do not support IP_RECVTOS on dual-stack sockets :(
         // older macos versions also don't have the flag and will error out if we don't ignore it
-        #[cfg(not(any(target_os = "openbsd", target_os = "netbsd", solarish)))]
+        #[cfg(not(any(target_os = "openbsd", target_os = "netbsd", target_os = "dragonfly", solarish)))]
         if is_ipv4 || !io.only_v6()? {
             if let Err(_err) =
                 set_socket_option(&*io, libc::IPPROTO_IP, libc::IP_RECVTOS, OPTION_ON)
@@ -278,7 +280,7 @@ fn send(
 ) -> io::Result<()> {
     #[allow(unused_mut)] // only mutable on FreeBSD
     let mut encode_src_ip = true;
-    #[cfg(target_os = "freebsd")]
+    #[cfg(any(target_os = "freebsd", target_os = "dragonfly"))]
     {
         let addr = io.local_addr()?;
         let is_ipv4 = addr.family() == libc::AF_INET as libc::sa_family_t;
@@ -452,7 +454,7 @@ fn send(state: &UdpSocketState, io: Sock
     }
 }
 
-#[cfg(not(any(apple, target_os = "openbsd", target_os = "netbsd", solarish)))]
+#[cfg(not(any(apple, target_os = "openbsd", target_os = "netbsd", target_os = "dragonfly", solarish)))]
 fn recv(io: SockRef<'_>, bufs: &mut [IoSliceMut<'_>], meta: &mut [RecvMeta]) -> io::Result<usize> {
     let mut names = [MaybeUninit::<libc::sockaddr_storage>::uninit(); BATCH_SIZE];
     let mut ctrls = [cmsg::Aligned(MaybeUninit::<[u8; CMSG_LEN]>::uninit()); BATCH_SIZE];
@@ -519,7 +521,7 @@ fn recv(io: SockRef<'_>, bufs: &mut [IoS
     Ok(msg_count as usize)
 }
 
-#[cfg(any(target_os = "openbsd", target_os = "netbsd", solarish, apple_slow))]
+#[cfg(any(target_os = "openbsd", target_os = "netbsd", target_os = "dragonfly", solarish, apple_slow))]
 fn recv(io: SockRef<'_>, bufs: &mut [IoSliceMut<'_>], meta: &mut [RecvMeta]) -> io::Result<usize> {
     let mut name = MaybeUninit::<libc::sockaddr_storage>::uninit();
     let mut ctrl = cmsg::Aligned(MaybeUninit::<[u8; CMSG_LEN]>::uninit());
@@ -689,7 +691,7 @@ fn decode_recv(
                 ecn_bits = cmsg::decode::<u8, libc::cmsghdr>(cmsg);
             },
             // FreeBSD uses IP_RECVTOS here, and we can be liberal because cmsgs are opt-in.
-            #[cfg(not(any(target_os = "openbsd", target_os = "netbsd", solarish)))]
+            #[cfg(not(any(target_os = "openbsd", target_os = "netbsd", target_os = "dragonfly", solarish)))]
             (libc::IPPROTO_IP, libc::IP_RECVTOS) => unsafe {
                 ecn_bits = cmsg::decode::<u8, libc::cmsghdr>(cmsg);
             },
