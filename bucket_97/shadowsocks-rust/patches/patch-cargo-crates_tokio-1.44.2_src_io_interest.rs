--- cargo-crates/tokio-1.44.2/src/io/interest.rs.orig	2025-04-29 04:32:32 UTC
+++ cargo-crates/tokio-1.44.2/src/io/interest.rs
@@ -10,7 +10,7 @@ use std::ops;
 const READABLE: usize = 0b0001;
 const WRITABLE: usize = 0b0010;
 // The following are not available on all platforms.
-#[cfg(target_os = "freebsd")]
+#[cfg(any(target_os = "freebsd", target_os = "dragonfly"))]
 const AIO: usize = 0b0100;
 #[cfg(target_os = "freebsd")]
 const LIO: usize = 0b1000;
@@ -33,11 +33,11 @@ impl Interest {
     // building documentation.
     cfg_aio! {
         /// Interest for POSIX AIO.
-        #[cfg(target_os = "freebsd")]
+        #[cfg(any(target_os = "freebsd", target_os = "dragonfly"))]
         pub const AIO: Interest = Interest(AIO);
 
         /// Interest for POSIX AIO.
-        #[cfg(not(target_os = "freebsd"))]
+        #[cfg(not(any(target_os = "freebsd", target_os = "dragonfly")))]
         pub const AIO: Interest = Interest(READABLE);
 
         /// Interest for POSIX AIO `lio_listio` events.
@@ -121,7 +121,7 @@ impl Interest {
         self.0 & ERROR != 0
     }
 
-    #[cfg(target_os = "freebsd")]
+    #[cfg(any(target_os = "freebsd", target_os = "dragonfly"))]
     const fn is_aio(self) -> bool {
         self.0 & AIO != 0
     }
@@ -227,7 +227,7 @@ impl Interest {
             mio_add(&mut mio, mio::Interest::PRIORITY);
         }
 
-        #[cfg(target_os = "freebsd")]
+        #[cfg(any(target_os = "freebsd", target_os = "dragonfly"))]
         if self.is_aio() {
             mio_add(&mut mio, mio::Interest::AIO);
         }
@@ -312,7 +312,7 @@ impl fmt::Debug for Interest {
             separator = true;
         }
 
-        #[cfg(target_os = "freebsd")]
+        #[cfg(any(target_os = "freebsd", target_os = "dragonfly"))]
         if self.is_aio() {
             if separator {
                 write!(fmt, " | ")?;
