--- library/std/src/sys/fs/unix.rs.orig	2026-01-19 16:34:28 UTC
+++ library/std/src/sys/fs/unix.rs
@@ -1290,6 +1290,7 @@ impl File {
 
     #[cfg(any(
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "linux",
         target_os = "netbsd",
@@ -1315,6 +1316,7 @@ impl File {
 
     #[cfg(not(any(
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "linux",
         target_os = "netbsd",
@@ -1331,6 +1333,7 @@ impl File {
 
     #[cfg(any(
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "linux",
         target_os = "netbsd",
@@ -1356,6 +1359,7 @@ impl File {
 
     #[cfg(not(any(
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "linux",
         target_os = "netbsd",
@@ -1372,6 +1376,7 @@ impl File {
 
     #[cfg(any(
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "linux",
         target_os = "netbsd",
@@ -1413,6 +1418,7 @@ impl File {
 
     #[cfg(not(any(
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "linux",
         target_os = "netbsd",
@@ -1432,6 +1438,7 @@ impl File {
 
     #[cfg(any(
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "linux",
         target_os = "netbsd",
@@ -1473,6 +1480,7 @@ impl File {
 
     #[cfg(not(any(
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "linux",
         target_os = "netbsd",
@@ -1492,6 +1500,7 @@ impl File {
 
     #[cfg(any(
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "linux",
         target_os = "netbsd",
@@ -1517,6 +1526,7 @@ impl File {
 
     #[cfg(not(any(
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "linux",
         target_os = "netbsd",
