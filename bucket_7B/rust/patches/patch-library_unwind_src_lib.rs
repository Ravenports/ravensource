--- library/unwind/src/lib.rs.orig	2026-07-14 15:13:08 UTC
+++ library/unwind/src/lib.rs
@@ -183,7 +183,7 @@ unsafe extern "C" {}
 unsafe extern "C" {}
 
 #[cfg(target_os = "dragonfly")]
-#[link(name = "gcc_pic")]
+#[link(name = "gcc_s")]
 unsafe extern "C" {}
 
 #[cfg(target_os = "haiku")]
