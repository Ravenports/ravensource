--- src/wutil/dir_iter.rs.orig	2025-10-07 20:56:06 UTC
+++ src/wutil/dir_iter.rs
@@ -285,11 +285,11 @@ impl DirIter {
 
         self.entry.reset();
         self.entry.name = str2wcstring(d_name);
-        #[cfg(any(target_os = "freebsd", target_os = "netbsd", target_os = "openbsd"))]
+        #[cfg(any(target_os = "freebsd", target_os = "netbsd", target_os = "openbsd", target_os = "dragonfly"))]
         {
             self.entry.inode = dent.d_fileno;
         }
-        #[cfg(not(any(target_os = "freebsd", target_os = "netbsd", target_os = "openbsd")))]
+        #[cfg(not(any(target_os = "freebsd", target_os = "netbsd", target_os = "openbsd", target_os = "dragonfly")))]
         {
             self.entry.inode = dent.d_ino;
         }
