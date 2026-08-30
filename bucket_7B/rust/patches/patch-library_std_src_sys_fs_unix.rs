--- library/std/src/sys/fs/unix.rs.orig	2026-07-14 15:13:08 UTC
+++ library/std/src/sys/fs/unix.rs
@@ -1443,6 +1443,7 @@ impl File {
 
     #[cfg(any(
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "hurd",
         target_os = "linux",
@@ -1469,6 +1470,7 @@ impl File {
 
     #[cfg(not(any(
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "hurd",
         target_os = "linux",
@@ -1486,6 +1488,7 @@ impl File {
 
     #[cfg(any(
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "hurd",
         target_os = "linux",
@@ -1512,6 +1515,7 @@ impl File {
 
     #[cfg(not(any(
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "hurd",
         target_os = "linux",
@@ -1529,6 +1533,7 @@ impl File {
 
     #[cfg(any(
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "hurd",
         target_os = "linux",
@@ -1571,6 +1576,7 @@ impl File {
 
     #[cfg(not(any(
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "hurd",
         target_os = "linux",
@@ -1591,6 +1597,7 @@ impl File {
 
     #[cfg(any(
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "hurd",
         target_os = "linux",
@@ -1633,6 +1640,7 @@ impl File {
 
     #[cfg(not(any(
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "hurd",
         target_os = "linux",
@@ -1653,6 +1661,7 @@ impl File {
 
     #[cfg(any(
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "hurd",
         target_os = "linux",
@@ -1679,6 +1688,7 @@ impl File {
 
     #[cfg(not(any(
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "hurd",
         target_os = "linux",
