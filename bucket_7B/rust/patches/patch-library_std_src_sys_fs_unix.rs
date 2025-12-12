--- library/std/src/sys/fs/unix.rs.orig	2025-12-08 12:52:32 UTC
+++ library/std/src/sys/fs/unix.rs
@@ -1287,6 +1287,7 @@ impl File {
 
     #[cfg(any(
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "linux",
         target_os = "netbsd",
@@ -1311,6 +1312,7 @@ impl File {
 
     #[cfg(not(any(
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "linux",
         target_os = "netbsd",
@@ -1326,6 +1328,7 @@ impl File {
 
     #[cfg(any(
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "linux",
         target_os = "netbsd",
@@ -1350,6 +1353,7 @@ impl File {
 
     #[cfg(not(any(
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "linux",
         target_os = "netbsd",
@@ -1365,6 +1369,7 @@ impl File {
 
     #[cfg(any(
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "linux",
         target_os = "netbsd",
@@ -1405,6 +1410,7 @@ impl File {
 
     #[cfg(not(any(
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "linux",
         target_os = "netbsd",
@@ -1423,6 +1429,7 @@ impl File {
 
     #[cfg(any(
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "linux",
         target_os = "netbsd",
@@ -1463,6 +1470,7 @@ impl File {
 
     #[cfg(not(any(
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "linux",
         target_os = "netbsd",
@@ -1481,6 +1489,7 @@ impl File {
 
     #[cfg(any(
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "linux",
         target_os = "netbsd",
@@ -1505,6 +1514,7 @@ impl File {
 
     #[cfg(not(any(
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "linux",
         target_os = "netbsd",
