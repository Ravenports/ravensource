--- third_party/rust/quinn-udp/src/unix.rs.orig	2024-10-13 21:12:29 UTC
+++ third_party/rust/quinn-udp/src/unix.rs
@@ -27,12 +27,14 @@ use super::{
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
@@ -62,6 +64,7 @@ impl UdpSocketState {
             || cfg!(target_os = "freebsd")
             || cfg!(target_os = "openbsd")
             || cfg!(target_os = "netbsd")
+            || cfg!(target_os = "dragonfly")
             || cfg!(target_os = "macos")
             || cfg!(target_os = "ios")
             || cfg!(target_os = "android")
@@ -87,7 +90,7 @@ impl UdpSocketState {
 
         // mac and ios do not support IP_RECVTOS on dual-stack sockets :(
         // older macos versions also don't have the flag and will error out if we don't ignore it
-        #[cfg(not(any(target_os = "openbsd", target_os = "netbsd")))]
+        #[cfg(not(any(target_os = "openbsd", target_os = "netbsd", target_os = "dragonfly")))]
         if is_ipv4 || !io.only_v6()? {
             #[allow(unused_variables)]
             if let Err(err) = set_socket_option(&*io, libc::IPPROTO_IP, libc::IP_RECVTOS, OPTION_ON)
@@ -141,6 +144,7 @@ impl UdpSocketState {
             target_os = "freebsd",
             target_os = "openbsd",
             target_os = "netbsd",
+            target_os = "dragonfly",
             target_os = "macos",
             target_os = "ios"
         ))]
@@ -246,7 +250,7 @@ fn send(
 ) -> io::Result<()> {
     #[allow(unused_mut)] // only mutable on FreeBSD
     let mut encode_src_ip = true;
-    #[cfg(target_os = "freebsd")]
+    #[cfg(any(target_os = "freebsd", target_os = "dragonfly"))]
     {
         let addr = io.local_addr()?;
         let is_ipv4 = addr.family() == libc::AF_INET as libc::sa_family_t;
@@ -372,7 +376,7 @@ fn send(state: &UdpSocketState, io: Sock
     Ok(())
 }
 
-#[cfg(not(any(target_os = "macos", target_os = "ios", target_os = "openbsd")))]
+#[cfg(not(any(target_os = "macos", target_os = "ios", target_os = "openbsd", target_os = "dragonfly")))]
 fn recv(io: SockRef<'_>, bufs: &mut [IoSliceMut<'_>], meta: &mut [RecvMeta]) -> io::Result<usize> {
     let mut names = [MaybeUninit::<libc::sockaddr_storage>::uninit(); BATCH_SIZE];
     let mut ctrls = [cmsg::Aligned(MaybeUninit::<[u8; CMSG_LEN]>::uninit()); BATCH_SIZE];
@@ -409,7 +413,7 @@ fn recv(io: SockRef<'_>, bufs: &mut [IoS
     Ok(msg_count as usize)
 }
 
-#[cfg(any(target_os = "macos", target_os = "ios", target_os = "openbsd"))]
+#[cfg(any(target_os = "macos", target_os = "ios", target_os = "openbsd", target_os = "dragonfly"))]
 fn recv(io: SockRef<'_>, bufs: &mut [IoSliceMut<'_>], meta: &mut [RecvMeta]) -> io::Result<usize> {
     let mut name = MaybeUninit::<libc::sockaddr_storage>::uninit();
     let mut ctrl = cmsg::Aligned(MaybeUninit::<[u8; CMSG_LEN]>::uninit());
@@ -438,7 +442,7 @@ fn recv(io: SockRef<'_>, bufs: &mut [IoS
 ///
 /// It uses [`libc::syscall`] instead of [`libc::recvmmsg`]
 /// to avoid linking error on systems where libc does not contain `recvmmsg`.
-#[cfg(not(any(target_os = "macos", target_os = "ios", target_os = "openbsd")))]
+#[cfg(not(any(target_os = "macos", target_os = "ios", target_os = "openbsd", target_os = "dragonfly")))]
 unsafe fn recvmmsg_with_fallback(
     sockfd: libc::c_int,
     msgvec: *mut libc::mmsghdr,
@@ -447,7 +451,7 @@ unsafe fn recvmmsg_with_fallback(
     let flags = 0;
     let timeout = ptr::null_mut::<libc::timespec>();
 
-    #[cfg(not(any(target_os = "freebsd", target_os = "netbsd")))]
+    #[cfg(not(any(target_os = "freebsd", target_os = "netbsd", target_os = "dragonfly")))]
     {
         let ret =
             libc::syscall(libc::SYS_recvmmsg, sockfd, msgvec, vlen, flags, timeout) as libc::c_int;
@@ -458,9 +462,9 @@ unsafe fn recvmmsg_with_fallback(
 
     // libc on FreeBSD and NetBSD implement `recvmmsg` as a high-level abstraction over
     // `recvmsg`, thus `SYS_recvmmsg` constant and direct system call do not exist
-    #[cfg(any(target_os = "freebsd", target_os = "netbsd"))]
+    #[cfg(any(target_os = "freebsd", target_os = "netbsd", target_os = "dragonfly"))]
     {
-        #[cfg(target_os = "freebsd")]
+        #[cfg(any(target_os = "freebsd", target_os = "dragonfly"))]
         let vlen = vlen as usize;
         let ret = libc::recvmmsg(sockfd, msgvec, vlen, flags, timeout) as libc::c_int;
         if ret != -1 {
@@ -481,7 +485,7 @@ unsafe fn recvmmsg_with_fallback(
 /// Fallback implementation of `recvmmsg` using `recvmsg`
 /// for systems which do not support `recvmmsg`
 /// such as Linux <2.6.33.
-#[cfg(not(any(target_os = "macos", target_os = "ios", target_os = "openbsd")))]
+#[cfg(not(any(target_os = "macos", target_os = "ios", target_os = "openbsd", target_os = "dragonfly")))]
 unsafe fn recvmmsg_fallback(
     sockfd: libc::c_int,
     msgvec: *mut libc::mmsghdr,
@@ -570,6 +574,7 @@ fn prepare_msg(
                     target_os = "freebsd",
                     target_os = "openbsd",
                     target_os = "netbsd",
+                    target_os = "dragonfly",
                     target_os = "macos",
                     target_os = "ios",
                 ))]
@@ -630,7 +635,7 @@ fn decode_recv(
                 ecn_bits = cmsg::decode::<u8, libc::cmsghdr>(cmsg);
             },
             // FreeBSD uses IP_RECVTOS here, and we can be liberal because cmsgs are opt-in.
-            #[cfg(not(any(target_os = "openbsd", target_os = "netbsd")))]
+            #[cfg(not(any(target_os = "openbsd", target_os = "netbsd", target_os = "dragonfly")))]
             (libc::IPPROTO_IP, libc::IP_RECVTOS) => unsafe {
                 ecn_bits = cmsg::decode::<u8, libc::cmsghdr>(cmsg);
             },
@@ -657,6 +662,7 @@ fn decode_recv(
                 target_os = "freebsd",
                 target_os = "openbsd",
                 target_os = "netbsd",
+                target_os = "dragonfly",
                 target_os = "macos",
                 target_os = "ios",
             ))]
