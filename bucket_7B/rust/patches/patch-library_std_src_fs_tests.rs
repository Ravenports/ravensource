--- library/std/src/fs/tests.rs.orig	2025-10-28 16:34:16 UTC
+++ library/std/src/fs/tests.rs
@@ -3,6 +3,7 @@ use rand::RngCore;
 #[cfg(any(
     windows,
     target_os = "freebsd",
+    target_os = "dragonfly",
     target_os = "linux",
     target_os = "netbsd",
     target_vendor = "apple",
@@ -12,6 +13,7 @@ use crate::char::MAX_LEN_UTF8;
 #[cfg(any(
     windows,
     target_os = "freebsd",
+    target_os = "dragonfly",
     target_os = "linux",
     target_os = "netbsd",
     target_vendor = "apple",
@@ -224,6 +226,7 @@ fn file_test_io_seek_and_write() {
 #[cfg(any(
     windows,
     target_os = "freebsd",
+    target_os = "dragonfly",
     target_os = "linux",
     target_os = "netbsd",
     target_os = "solaris",
@@ -248,6 +251,7 @@ fn file_lock_multiple_shared() {
 #[cfg(any(
     windows,
     target_os = "freebsd",
+    target_os = "dragonfly",
     target_os = "linux",
     target_os = "netbsd",
     target_os = "solaris",
@@ -273,6 +277,7 @@ fn file_lock_blocking() {
 #[cfg(any(
     windows,
     target_os = "freebsd",
+    target_os = "dragonfly",
     target_os = "linux",
     target_os = "netbsd",
     target_os = "solaris",
@@ -295,6 +300,7 @@ fn file_lock_drop() {
 #[cfg(any(
     windows,
     target_os = "freebsd",
+    target_os = "dragonfly",
     target_os = "linux",
     target_os = "netbsd",
     target_os = "solaris",
