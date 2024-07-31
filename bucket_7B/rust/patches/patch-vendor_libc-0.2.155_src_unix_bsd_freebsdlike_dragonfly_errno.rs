--- vendor/libc-0.2.155/src/unix/bsd/freebsdlike/dragonfly/errno.rs.orig	2006-07-24 01:21:28 UTC
+++ vendor/libc-0.2.155/src/unix/bsd/freebsdlike/dragonfly/errno.rs
@@ -1,7 +1,6 @@
 // DragonFlyBSD's __error function is declared with "static inline", so it must
 // be implemented in the libc crate, as a pointer to a static thread_local.
 f! {
-    #[deprecated(since = "0.2.77", note = "Use `__errno_location()` instead")]
     pub fn __error() -> *mut ::c_int {
         &mut errno
     }
