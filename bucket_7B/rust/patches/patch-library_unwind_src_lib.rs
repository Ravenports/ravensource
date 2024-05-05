--- library/unwind/src/lib.rs.orig	2024-04-29 14:03:23 UTC
+++ library/unwind/src/lib.rs
@@ -150,7 +150,7 @@ extern "C" {}
 extern "C" {}
 
 #[cfg(target_os = "dragonfly")]
-#[link(name = "gcc_pic")]
+#[link(name = "gcc_s")]
 extern "C" {}
 
 #[cfg(target_os = "haiku")]
