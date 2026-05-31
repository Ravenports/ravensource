--- library/unwind/src/lib.rs.orig	2026-05-25 23:21:07 UTC
+++ library/unwind/src/lib.rs
@@ -182,7 +182,7 @@ unsafe extern "C" {}
 unsafe extern "C" {}
 
 #[cfg(target_os = "dragonfly")]
-#[link(name = "gcc_pic")]
+#[link(name = "gcc_s")]
 unsafe extern "C" {}
 
 #[cfg(target_os = "haiku")]
