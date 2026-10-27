--- library/std/src/sys/fs/unix.rs.orig	2026-10-13 01:48:49 UTC
+++ library/std/src/sys/fs/unix.rs
@@ -322,7 +322,7 @@ fn get_path_from_fd(fd: c_int) -> Option
         run_path_with_cstr(&p, &readlink).ok()
     }
 
-    #[cfg(any(target_vendor = "apple", target_os = "netbsd"))]
+    #[cfg(any(target_vendor = "apple", target_os = "netbsd", target_os = "dragonfly"))]
     fn get_path(fd: c_int) -> Option<PathBuf> {
         // FIXME: The use of PATH_MAX is generally not encouraged, but it
         // is inevitable in this case because Apple targets and NetBSD define `fcntl`
@@ -379,6 +379,7 @@ fn get_path_from_fd(fd: c_int) -> Option
         target_os = "linux",
         target_os = "vxworks",
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "netbsd",
         target_os = "illumos",
         target_os = "solaris",
@@ -1322,6 +1323,7 @@ impl File {
         cfg_select! {
             any(
                 target_os = "freebsd",
+                target_os = "dragonfly",
                 target_os = "fuchsia",
                 target_os = "hurd",
                 target_os = "linux",
@@ -1346,6 +1348,7 @@ impl File {
         cfg_select! {
             any(
                 target_os = "freebsd",
+                target_os = "dragonfly",
                 target_os = "fuchsia",
                 target_os = "hurd",
                 target_os = "linux",
@@ -1370,6 +1373,7 @@ impl File {
         cfg_select! {
             any(
                 target_os = "freebsd",
+                target_os = "dragonfly",
                 target_os = "fuchsia",
                 target_os = "hurd",
                 target_os = "linux",
@@ -1405,6 +1409,7 @@ impl File {
         cfg_select! {
                 any(
                 target_os = "freebsd",
+                target_os = "dragonfly",
                 target_os = "fuchsia",
                 target_os = "hurd",
                 target_os = "linux",
@@ -1440,6 +1445,7 @@ impl File {
         cfg_select! {
             any(
                 target_os = "freebsd",
+                target_os = "dragonfly",
                 target_os = "fuchsia",
                 target_os = "hurd",
                 target_os = "linux",
