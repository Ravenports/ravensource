--- library/unwind/src/lib.rs.orig	2025-12-08 12:52:32 UTC
+++ library/unwind/src/lib.rs
@@ -166,7 +166,7 @@ unsafe extern "C" {}
 unsafe extern "C" {}
 
 #[cfg(target_os = "dragonfly")]
-#[link(name = "gcc_pic")]
+#[link(name = "gcc_s")]
 unsafe extern "C" {}
 
 #[cfg(target_os = "haiku")]
