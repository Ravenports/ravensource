--- cargo-crates/getrandom-0.1.13/src/util_libc.rs.orig	2019-10-24 09:46:05 UTC
+++ cargo-crates/getrandom-0.1.13/src/util_libc.rs
@@ -10,6 +10,7 @@ use crate::util::LazyUsize;
 use crate::Error;
 use core::num::NonZeroU32;
 use core::ptr::NonNull;
+extern crate errno_dragonfly;
 
 cfg_if! {
     if #[cfg(any(target_os = "netbsd", target_os = "openbsd", target_os = "android"))] {
@@ -18,10 +19,12 @@ cfg_if! {
         use libc::__errno_location as errno_location;
     } else if #[cfg(any(target_os = "solaris", target_os = "illumos"))] {
         use libc::___errno as errno_location;
-    } else if #[cfg(any(target_os = "macos", target_os = "freebsd", target_os = "dragonfly"))] {
+    } else if #[cfg(any(target_os = "macos", target_os = "freebsd"))] {
         use libc::__error as errno_location;
     } else if #[cfg(target_os = "haiku")] {
         use libc::_errnop as errno_location;
+    } else if #[cfg(target_os = "dragonfly")] {
+        use errno_dragonfly::errno_location;
     }
 }
 
