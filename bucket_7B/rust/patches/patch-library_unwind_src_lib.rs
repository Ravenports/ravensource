--- library/unwind/src/lib.rs.orig	2023-11-13 04:10:51 UTC
+++ library/unwind/src/lib.rs
@@ -138,7 +138,7 @@ extern "C" {}
 extern "C" {}
 
 #[cfg(target_os = "dragonfly")]
-#[link(name = "gcc_pic")]
+#[link(name = "gcc_s")]
 extern "C" {}
 
 #[cfg(target_os = "haiku")]
