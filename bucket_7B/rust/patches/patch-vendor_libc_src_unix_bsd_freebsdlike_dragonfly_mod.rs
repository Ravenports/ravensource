--- vendor/libc/src/unix/bsd/freebsdlike/dragonfly/mod.rs.orig	2020-07-31 22:07:15 UTC
+++ vendor/libc/src/unix/bsd/freebsdlike/dragonfly/mod.rs
@@ -1051,9 +1051,18 @@ f! {
         (_CMSG_ALIGN(::mem::size_of::<::cmsghdr>()) +
             _CMSG_ALIGN(length as usize)) as ::c_uint
     }
+
+    // DragonFlyBSD's __error function is declared with "static inline", so it must
+    // be implemented in the libc crate, as a pointer to a static thread_local.
+    pub fn __error() -> *mut ::c_int {
+        &mut errno
+    }
 }
 
 extern "C" {
+    #[thread_local]
+    pub static mut errno: ::c_int;
+
     pub fn setgrent();
     pub fn mprotect(
         addr: *mut ::c_void,
