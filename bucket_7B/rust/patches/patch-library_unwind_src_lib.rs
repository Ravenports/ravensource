--- library/unwind/src/lib.rs.orig	2024-04-09 17:20:09 UTC
+++ library/unwind/src/lib.rs
@@ -144,7 +144,7 @@ extern "C" {}
 extern "C" {}
 
 #[cfg(target_os = "dragonfly")]
-#[link(name = "gcc_pic")]
+#[link(name = "gcc_s")]
 extern "C" {}
 
 #[cfg(target_os = "haiku")]
