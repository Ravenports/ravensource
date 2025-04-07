--- library/unwind/src/lib.rs.orig	2025-03-31 21:37:24 UTC
+++ library/unwind/src/lib.rs
@@ -153,7 +153,7 @@ unsafe extern "C" {}
 unsafe extern "C" {}
 
 #[cfg(target_os = "dragonfly")]
-#[link(name = "gcc_pic")]
+#[link(name = "gcc_s")]
 unsafe extern "C" {}
 
 #[cfg(target_os = "haiku")]
