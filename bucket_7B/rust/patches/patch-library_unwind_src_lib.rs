--- library/unwind/src/lib.rs.orig	2026-11-09 22:11:55 UTC
+++ library/unwind/src/lib.rs
@@ -213,7 +213,7 @@ unsafe extern "C" {}
 unsafe extern "C" {}
 
 #[cfg(target_os = "dragonfly")]
-#[link(name = "gcc_pic")]
+#[link(name = "gcc_s")]
 unsafe extern "C" {}
 
 #[cfg(target_os = "haiku")]
