--- library/unwind/src/lib.rs.orig	2023-08-03 12:13:07 UTC
+++ library/unwind/src/lib.rs
@@ -137,7 +137,7 @@ extern "C" {}
 extern "C" {}
 
 #[cfg(target_os = "dragonfly")]
-#[link(name = "gcc_pic")]
+#[link(name = "gcc_s")]
 extern "C" {}
 
 #[cfg(target_os = "haiku")]
