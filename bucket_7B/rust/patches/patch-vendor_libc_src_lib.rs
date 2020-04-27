--- vendor/libc/src/lib.rs.orig	2020-04-21 00:01:49 UTC
+++ vendor/libc/src/lib.rs
@@ -27,7 +27,7 @@
     feature = "rustc-dep-of-std",
     feature(cfg_target_vendor, link_cfg, no_core)
 )]
-#![cfg_attr(libc_thread_local, feature(thread_local))]
+#![feature(thread_local)]
 // Enable extra lints:
 #![cfg_attr(feature = "extra_traits", deny(missing_debug_implementations))]
 #![deny(missing_copy_implementations, safe_packed_borrows)]
