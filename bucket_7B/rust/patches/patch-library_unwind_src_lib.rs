--- library/unwind/src/lib.rs.orig	2025-05-09 20:37:37 UTC
+++ library/unwind/src/lib.rs
@@ -154,7 +154,7 @@ unsafe extern "C" {}
 unsafe extern "C" {}
 
 #[cfg(target_os = "dragonfly")]
-#[link(name = "gcc_pic")]
+#[link(name = "gcc_s")]
 unsafe extern "C" {}
 
 #[cfg(target_os = "haiku")]
