--- library/std/src/fs/tests.rs.orig	2026-07-14 15:13:08 UTC
+++ library/std/src/fs/tests.rs
@@ -213,6 +213,7 @@ fn file_lock_multiple_shared() {
         target_os = "aix",
         target_os = "cygwin",
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "hurd",
         target_os = "illumos",
@@ -247,6 +248,7 @@ fn file_lock_blocking() {
         target_os = "aix",
         target_os = "cygwin",
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "hurd",
         target_os = "illumos",
@@ -278,6 +280,8 @@ fn file_lock_drop() {
         target_os = "aix",
         target_os = "cygwin",
         target_os = "freebsd",
+        target_os = "dragonfly",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "hurd",
         target_os = "illumos",
