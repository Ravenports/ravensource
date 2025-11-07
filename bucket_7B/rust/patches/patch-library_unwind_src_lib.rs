--- library/unwind/src/lib.rs.orig	2025-09-14 15:05:11 UTC
+++ library/unwind/src/lib.rs
@@ -154,7 +154,7 @@ unsafe extern "C" {}
 unsafe extern "C" {}
 
 #[cfg(target_os = "dragonfly")]
-#[link(name = "gcc_pic")]
+#[link(name = "gcc_s")]
 unsafe extern "C" {}
 
 #[cfg(target_os = "haiku")]
