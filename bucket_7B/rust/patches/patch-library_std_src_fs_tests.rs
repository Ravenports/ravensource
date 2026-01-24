--- library/std/src/fs/tests.rs.orig	2026-01-19 16:34:28 UTC
+++ library/std/src/fs/tests.rs
@@ -211,6 +211,7 @@ fn file_test_io_seek_and_write() {
         target_os = "aix",
         target_os = "cygwin",
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "illumos",
         target_os = "linux",
@@ -243,6 +244,7 @@ fn file_lock_multiple_shared() {
         target_os = "aix",
         target_os = "cygwin",
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "illumos",
         target_os = "linux",
@@ -276,6 +278,7 @@ fn file_lock_blocking() {
         target_os = "aix",
         target_os = "cygwin",
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "illumos",
         target_os = "linux",
@@ -306,6 +309,7 @@ fn file_lock_drop() {
         target_os = "aix",
         target_os = "cygwin",
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "illumos",
         target_os = "linux",
