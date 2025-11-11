--- library/std/src/sys/fs/unix.rs.orig	2025-11-07 03:39:30 UTC
+++ library/std/src/sys/fs/unix.rs
@@ -1281,6 +1281,7 @@ impl File {
 
     #[cfg(any(
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "linux",
         target_os = "netbsd",
@@ -1305,6 +1306,7 @@ impl File {
 
     #[cfg(not(any(
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "linux",
         target_os = "netbsd",
@@ -1320,6 +1322,7 @@ impl File {
 
     #[cfg(any(
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "linux",
         target_os = "netbsd",
@@ -1344,6 +1347,7 @@ impl File {
 
     #[cfg(not(any(
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "linux",
         target_os = "netbsd",
@@ -1359,6 +1363,7 @@ impl File {
 
     #[cfg(any(
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "linux",
         target_os = "netbsd",
@@ -1399,6 +1404,7 @@ impl File {
 
     #[cfg(not(any(
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "linux",
         target_os = "netbsd",
@@ -1417,6 +1423,7 @@ impl File {
 
     #[cfg(any(
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "linux",
         target_os = "netbsd",
@@ -1457,6 +1464,7 @@ impl File {
 
     #[cfg(not(any(
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "linux",
         target_os = "netbsd",
@@ -1475,6 +1483,7 @@ impl File {
 
     #[cfg(any(
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "linux",
         target_os = "netbsd",
@@ -1499,6 +1508,7 @@ impl File {
 
     #[cfg(not(any(
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "linux",
         target_os = "netbsd",
