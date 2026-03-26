--- library/std/src/fs/tests.rs.orig	2026-03-02 23:18:25 UTC
+++ library/std/src/fs/tests.rs
@@ -215,6 +215,7 @@ fn file_test_io_seek_and_write() {
         target_os = "aix",
         target_os = "cygwin",
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "hurd",
         target_os = "illumos",
@@ -248,6 +249,7 @@ fn file_lock_multiple_shared() {
         target_os = "aix",
         target_os = "cygwin",
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "hurd",
         target_os = "illumos",
@@ -282,6 +284,7 @@ fn file_lock_blocking() {
         target_os = "aix",
         target_os = "cygwin",
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "hurd",
         target_os = "illumos",
@@ -313,6 +316,7 @@ fn file_lock_drop() {
         target_os = "aix",
         target_os = "cygwin",
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "hurd",
         target_os = "illumos",
