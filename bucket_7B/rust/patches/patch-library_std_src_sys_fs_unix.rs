--- library/std/src/sys/fs/unix.rs.orig	2025-10-28 16:34:16 UTC
+++ library/std/src/sys/fs/unix.rs
@@ -1281,6 +1281,7 @@ impl File {
 
     #[cfg(any(
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "linux",
         target_os = "netbsd",
@@ -1304,6 +1305,7 @@ impl File {
 
     #[cfg(not(any(
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "linux",
         target_os = "netbsd",
@@ -1318,6 +1320,7 @@ impl File {
 
     #[cfg(any(
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "linux",
         target_os = "netbsd",
@@ -1341,6 +1344,7 @@ impl File {
 
     #[cfg(not(any(
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "linux",
         target_os = "netbsd",
@@ -1355,6 +1359,7 @@ impl File {
 
     #[cfg(any(
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "linux",
         target_os = "netbsd",
@@ -1394,6 +1399,7 @@ impl File {
 
     #[cfg(not(any(
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "linux",
         target_os = "netbsd",
@@ -1411,6 +1417,7 @@ impl File {
 
     #[cfg(any(
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "linux",
         target_os = "netbsd",
@@ -1450,6 +1457,7 @@ impl File {
 
     #[cfg(not(any(
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "linux",
         target_os = "netbsd",
@@ -1467,6 +1475,7 @@ impl File {
 
     #[cfg(any(
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "linux",
         target_os = "netbsd",
@@ -1490,6 +1499,7 @@ impl File {
 
     #[cfg(not(any(
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "linux",
         target_os = "netbsd",
