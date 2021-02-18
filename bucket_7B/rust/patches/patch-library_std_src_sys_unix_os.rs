--- library/std/src/sys/unix/os.rs.orig	2021-02-10 17:36:44 UTC
+++ library/std/src/sys/unix/os.rs
@@ -99,18 +99,6 @@ pub fn errno() -> i32 {
     unsafe { errno as i32 }
 }
 
-#[cfg(target_os = "dragonfly")]
-pub fn set_errno(e: i32) {
-    extern "C" {
-        #[thread_local]
-        static mut errno: c_int;
-    }
-
-    unsafe {
-        errno = e;
-    }
-}
-
 /// Gets a detailed string description for the given error number.
 pub fn error_string(errno: i32) -> String {
     extern "C" {
