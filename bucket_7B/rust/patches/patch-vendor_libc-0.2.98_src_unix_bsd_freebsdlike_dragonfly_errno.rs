--- vendor/libc-0.2.98/src/unix/bsd/freebsdlike/dragonfly/errno.rs.orig	2021-11-29 20:27:33 UTC
+++ vendor/libc-0.2.98/src/unix/bsd/freebsdlike/dragonfly/errno.rs
@@ -1,7 +1,6 @@
 // DragonFlyBSD's __error function is declared with "static inline", so it must
 // be implemented in the libc crate, as a pointer to a static thread_local.
 f! {
-    #[deprecated(since = "0.2.77", note = "Use `__errno_location()` instead")]
     pub fn __error() -> *mut ::c_int {
         &mut errno
     }
