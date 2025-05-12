--- cargo-crates/tokio-1.45.0/src/macros/cfg.rs.orig	2025-05-12 00:10:42 UTC
+++ cargo-crates/tokio-1.45.0/src/macros/cfg.rs
@@ -84,9 +84,9 @@ macro_rules! cfg_atomic_waker_impl {
 macro_rules! cfg_aio {
     ($($item:item)*) => {
         $(
-            #[cfg(all(any(docsrs, target_os = "freebsd"), feature = "net"))]
+            #[cfg(all(any(docsrs, any(target_os = "freebsd", target_os = "dragonfly")), feature = "net"))]
             #[cfg_attr(docsrs,
-                doc(cfg(all(target_os = "freebsd", feature = "net")))
+                doc(cfg(all(any(target_os = "freebsd", target_os = "dragonfly"), feature = "net")))
             )]
             $item
         )*
