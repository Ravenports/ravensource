--- library/unwind/src/lib.rs.orig	2025-01-27 23:20:59 UTC
+++ library/unwind/src/lib.rs
@@ -153,7 +153,7 @@ extern "C" {}
 extern "C" {}
 
 #[cfg(target_os = "dragonfly")]
-#[link(name = "gcc_pic")]
+#[link(name = "gcc_s")]
 extern "C" {}
 
 #[cfg(target_os = "haiku")]
