--- library/std/src/sys/fs/unix.rs.orig	2026-08-18 19:58:58 UTC
+++ library/std/src/sys/fs/unix.rs
@@ -25,6 +25,7 @@ use libc::fstatat64;
     target_os = "aix",
     target_os = "android",
     target_os = "freebsd",
+    target_os = "dragonfly",
     target_os = "fuchsia",
     target_os = "illumos",
     target_os = "nto",
@@ -40,6 +41,7 @@ use libc::readdir as readdir64;
     target_os = "aix",
     target_os = "android",
     target_os = "freebsd",
+    target_os = "dragonfly",
     target_os = "fuchsia",
     target_os = "hurd",
     target_os = "illumos",
@@ -408,6 +410,7 @@ fn get_path_from_fd(fd: c_int) -> Option
     target_os = "aix",
     target_os = "android",
     target_os = "freebsd",
+    target_os = "dragonfly",
     target_os = "fuchsia",
     target_os = "hurd",
     target_os = "illumos",
@@ -435,6 +438,7 @@ pub struct DirEntry {
     target_os = "aix",
     target_os = "android",
     target_os = "freebsd",
+    target_os = "dragonfly",
     target_os = "fuchsia",
     target_os = "hurd",
     target_os = "illumos",
@@ -463,6 +467,7 @@ struct dirent64_min {
     target_os = "aix",
     target_os = "android",
     target_os = "freebsd",
+    target_os = "dragonfly",
     target_os = "fuchsia",
     target_os = "hurd",
     target_os = "illumos",
@@ -862,6 +867,7 @@ impl Iterator for ReadDir {
         target_os = "aix",
         target_os = "android",
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "hurd",
         target_os = "illumos",
@@ -932,9 +938,9 @@ impl Iterator for ReadDir {
                 // only access those bytes.
                 #[cfg(not(target_os = "vita"))]
                 let entry = dirent64_min {
-                    #[cfg(target_os = "freebsd")]
+                    #[cfg(any(target_os = "freebsd", target_os = "dragonfly"))]
                     d_ino: (*entry_ptr).d_fileno,
-                    #[cfg(not(target_os = "freebsd"))]
+                    #[cfg(not(any(target_os = "freebsd", target_os = "dragonfly")))]
                     d_ino: (*entry_ptr).d_ino as u64,
                     #[cfg(not(any(
                         target_os = "solaris",
@@ -962,6 +968,7 @@ impl Iterator for ReadDir {
         target_os = "aix",
         target_os = "android",
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "hurd",
         target_os = "illumos",
@@ -1157,6 +1164,7 @@ impl DirEntry {
         target_os = "emscripten",
         target_os = "espidf",
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "haiku",
         target_os = "horizon",
@@ -1178,7 +1186,7 @@ impl DirEntry {
         self.entry.d_ino as u64
     }
 
-    #[cfg(any(target_os = "openbsd", target_os = "netbsd", target_os = "dragonfly"))]
+    #[cfg(any(target_os = "openbsd", target_os = "netbsd"))]
     pub fn ino(&self) -> u64 {
         self.entry.d_fileno as u64
     }
@@ -1193,7 +1201,6 @@ impl DirEntry {
     #[cfg(any(
         target_os = "netbsd",
         target_os = "openbsd",
-        target_os = "dragonfly",
         target_vendor = "apple",
     ))]
     fn name_bytes(&self) -> &[u8] {
@@ -1208,7 +1215,6 @@ impl DirEntry {
     #[cfg(not(any(
         target_os = "netbsd",
         target_os = "openbsd",
-        target_os = "dragonfly",
         target_vendor = "apple",
     )))]
     fn name_bytes(&self) -> &[u8] {
@@ -1218,6 +1224,7 @@ impl DirEntry {
     #[cfg(not(any(
         target_os = "android",
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "linux",
         target_os = "solaris",
         target_os = "illumos",
@@ -1236,6 +1243,7 @@ impl DirEntry {
     #[cfg(any(
         target_os = "android",
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "linux",
         target_os = "solaris",
         target_os = "illumos",
@@ -1469,6 +1477,7 @@ impl File {
         cfg_select! {
             any(
                 target_os = "freebsd",
+                target_os = "dragonfly",
                 target_os = "fuchsia",
                 target_os = "hurd",
                 target_os = "linux",
@@ -1493,6 +1502,7 @@ impl File {
         cfg_select! {
             any(
                 target_os = "freebsd",
+                target_os = "dragonfly",
                 target_os = "fuchsia",
                 target_os = "hurd",
                 target_os = "linux",
@@ -1517,6 +1527,7 @@ impl File {
         cfg_select! {
             any(
                 target_os = "freebsd",
+                target_os = "dragonfly",
                 target_os = "fuchsia",
                 target_os = "hurd",
                 target_os = "linux",
@@ -1552,6 +1563,7 @@ impl File {
         cfg_select! {
                 any(
                 target_os = "freebsd",
+                target_os = "dragonfly",
                 target_os = "fuchsia",
                 target_os = "hurd",
                 target_os = "linux",
@@ -1587,6 +1599,7 @@ impl File {
         cfg_select! {
             any(
                 target_os = "freebsd",
+                target_os = "dragonfly",
                 target_os = "fuchsia",
                 target_os = "hurd",
                 target_os = "linux",
