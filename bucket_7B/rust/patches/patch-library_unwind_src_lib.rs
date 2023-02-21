--- library/unwind/src/lib.rs.orig	2023-02-07 06:43:46 UTC
+++ library/unwind/src/lib.rs
@@ -121,7 +121,7 @@ extern "C" {}
 extern "C" {}
 
 #[cfg(target_os = "dragonfly")]
-#[link(name = "gcc_pic")]
+#[link(name = "gcc_s")]
 extern "C" {}
 
 #[cfg(target_os = "haiku")]
