--- library/unwind/src/lib.rs.orig	2023-12-21 16:55:28 UTC
+++ library/unwind/src/lib.rs
@@ -135,7 +135,7 @@ extern "C" {}
 extern "C" {}
 
 #[cfg(target_os = "dragonfly")]
-#[link(name = "gcc_pic")]
+#[link(name = "gcc_s")]
 extern "C" {}
 
 #[cfg(target_os = "haiku")]
