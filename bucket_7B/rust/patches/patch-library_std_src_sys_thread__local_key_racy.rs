--- library/std/src/sys/thread_local/key/racy.rs.orig	2026-10-13 01:48:49 UTC
+++ library/std/src/sys/thread_local/key/racy.rs
@@ -21,7 +21,7 @@ pub struct LazyKey {
 
 // Define a sentinel value that is likely not to be returned
 // as a TLS key.
-#[cfg(not(any(target_os = "nto", target_os = "qnx")))]
+#[cfg(not(any(target_os = "nto", target_os = "qnx", target_os = "dragonfly")))]
 const KEY_SENTVAL: usize = 0;
 // On QNX SDP, 0 is always returned when currently not in use.
 // Using 0 would mean to always create two keys and remove the first
@@ -29,6 +29,10 @@ const KEY_SENTVAL: usize = 0;
 #[cfg(any(target_os = "nto", target_os = "qnx"))]
 const KEY_SENTVAL: usize = libc::PTHREAD_KEYS_MAX + 1;
 
+// On DragonFly BSD, 0 is returned if the binary isn't linked to libpthread.
+#[cfg(target_os = "dragonfly")]
+const KEY_SENTVAL: usize = usize::MAX;
+
 impl LazyKey {
     pub const fn new(dtor: Option<unsafe extern "C" fn(*mut u8)>) -> LazyKey {
         LazyKey { key: AtomicUsize::new(KEY_SENTVAL), dtor }
