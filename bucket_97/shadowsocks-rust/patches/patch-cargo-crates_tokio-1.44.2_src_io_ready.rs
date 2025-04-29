--- cargo-crates/tokio-1.44.2/src/io/ready.rs.orig	2025-04-29 04:32:32 UTC
+++ cargo-crates/tokio-1.44.2/src/io/ready.rs
@@ -57,7 +57,7 @@ impl Ready {
     pub(crate) fn from_mio(event: &mio::event::Event) -> Ready {
         let mut ready = Ready::EMPTY;
 
-        #[cfg(all(target_os = "freebsd", feature = "net"))]
+        #[cfg(all(any(target_os = "freebsd", target_os = "dragonfly"), feature = "net"))]
         {
             if event.is_aio() {
                 ready |= Ready::READABLE;
