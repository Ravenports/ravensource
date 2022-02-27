--- library/std/src/os/dragonfly/raw.rs.orig	2022-02-23 04:07:21 UTC
+++ library/std/src/os/dragonfly/raw.rs
@@ -69,7 +69,7 @@ pub struct stat {
     #[stable(feature = "raw_ext", since = "1.1.0")]
     pub st_blocks: i64,
     #[stable(feature = "raw_ext", since = "1.1.0")]
-    pub st_blksize: u32,
+    pub st_blksize: blksize_t,
     #[stable(feature = "raw_ext", since = "1.1.0")]
     pub st_flags: u32,
     #[stable(feature = "raw_ext", since = "1.1.0")]
