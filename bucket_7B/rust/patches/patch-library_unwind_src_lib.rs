--- library/unwind/src/lib.rs.orig	2023-04-16 21:39:51 UTC
+++ library/unwind/src/lib.rs
@@ -121,7 +121,7 @@ extern "C" {}
 extern "C" {}
 
 #[cfg(target_os = "dragonfly")]
-#[link(name = "gcc_pic")]
+#[link(name = "gcc_s")]
 extern "C" {}
 
 #[cfg(target_os = "haiku")]
