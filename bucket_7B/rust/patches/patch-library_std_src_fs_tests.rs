--- library/std/src/fs/tests.rs.orig	2025-11-07 03:39:30 UTC
+++ library/std/src/fs/tests.rs
@@ -3,6 +3,7 @@ use rand::RngCore;
 #[cfg(any(
     windows,
     target_os = "freebsd",
+    target_os = "dragonfly",
     target_os = "linux",
     target_os = "netbsd",
     target_os = "illumos",
@@ -13,6 +14,7 @@ use crate::char::MAX_LEN_UTF8;
 #[cfg(any(
     windows,
     target_os = "freebsd",
+    target_os = "dragonfly",
     target_os = "linux",
     target_os = "netbsd",
     target_os = "illumos",
@@ -226,6 +228,7 @@ fn file_test_io_seek_and_write() {
 #[cfg(any(
     windows,
     target_os = "freebsd",
+    target_os = "dragonfly",
     target_os = "linux",
     target_os = "netbsd",
     target_os = "solaris",
@@ -251,6 +254,7 @@ fn file_lock_multiple_shared() {
 #[cfg(any(
     windows,
     target_os = "freebsd",
+    target_os = "dragonfly",
     target_os = "linux",
     target_os = "netbsd",
     target_os = "solaris",
@@ -277,6 +281,7 @@ fn file_lock_blocking() {
 #[cfg(any(
     windows,
     target_os = "freebsd",
+    target_os = "dragonfly",
     target_os = "linux",
     target_os = "netbsd",
     target_os = "solaris",
@@ -300,6 +305,7 @@ fn file_lock_drop() {
 #[cfg(any(
     windows,
     target_os = "freebsd",
+    target_os = "dragonfly",
     target_os = "linux",
     target_os = "netbsd",
     target_os = "solaris",
