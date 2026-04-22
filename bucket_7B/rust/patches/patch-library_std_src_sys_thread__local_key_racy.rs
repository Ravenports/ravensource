Resolve this issue on lld and dragonfly:
fatal runtime error: assertion failed: key as usize != KEY_SENTVAL, aborting

--- library/std/src/sys/thread_local/key/racy.rs.orig	2026-04-14 19:55:32 UTC
+++ library/std/src/sys/thread_local/key/racy.rs
@@ -21,14 +21,19 @@ pub struct LazyKey {
 
 // Define a sentinel value that is likely not to be returned
 // as a TLS key.
-#[cfg(not(target_os = "nto"))]
+#[cfg(not(any(target_os = "nto", target_os = "dragonfly")))]
 const KEY_SENTVAL: usize = 0;
+
 // On QNX Neutrino, 0 is always returned when currently not in use.
 // Using 0 would mean to always create two keys and remote the first
 // one (with value of 0) immediately afterwards.
 #[cfg(target_os = "nto")]
 const KEY_SENTVAL: usize = libc::PTHREAD_KEYS_MAX + 1;
 
+// On DragonFly BSD, 0 is returned if the binary isn't linked to libpthread.
+#[cfg(target_os = "dragonfly")]
+const KEY_SENTVAL: usize = usize::MAX;
+
 impl LazyKey {
     pub const fn new(dtor: Option<unsafe extern "C" fn(*mut u8)>) -> LazyKey {
         LazyKey { key: AtomicUsize::new(KEY_SENTVAL), dtor }
