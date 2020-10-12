--- vendor/libc/src/unix/bsd/freebsdlike/dragonfly/mod.rs.orig	2020-10-07 09:33:31 UTC
+++ vendor/libc/src/unix/bsd/freebsdlike/dragonfly/mod.rs
@@ -1056,9 +1056,18 @@ f! {
     pub fn WIFSIGNALED(status: ::c_int) -> bool {
         (status & 0o177) != 0o177 && (status & 0o177) != 0
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
