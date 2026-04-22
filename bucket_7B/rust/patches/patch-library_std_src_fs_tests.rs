--- library/std/src/fs/tests.rs.orig	2026-04-14 19:55:32 UTC
+++ library/std/src/fs/tests.rs
@@ -214,6 +214,7 @@ fn file_test_io_seek_and_write() {
         target_os = "aix",
         target_os = "cygwin",
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "hurd",
         target_os = "illumos",
@@ -247,6 +248,7 @@ fn file_lock_multiple_shared() {
         target_os = "aix",
         target_os = "cygwin",
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "hurd",
         target_os = "illumos",
@@ -281,6 +283,7 @@ fn file_lock_blocking() {
         target_os = "aix",
         target_os = "cygwin",
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "hurd",
         target_os = "illumos",
@@ -312,6 +315,7 @@ fn file_lock_drop() {
         target_os = "aix",
         target_os = "cygwin",
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "hurd",
         target_os = "illumos",
