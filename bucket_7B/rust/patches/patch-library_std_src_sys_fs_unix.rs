--- library/std/src/sys/fs/unix.rs.orig	2025-09-14 15:05:11 UTC
+++ library/std/src/sys/fs/unix.rs
@@ -1260,6 +1260,7 @@ impl File {
 
     #[cfg(any(
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "linux",
         target_os = "netbsd",
@@ -1273,6 +1274,7 @@ impl File {
 
     #[cfg(not(any(
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "linux",
         target_os = "netbsd",
@@ -1285,6 +1287,7 @@ impl File {
 
     #[cfg(any(
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "linux",
         target_os = "netbsd",
@@ -1298,6 +1301,7 @@ impl File {
 
     #[cfg(not(any(
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "linux",
         target_os = "netbsd",
@@ -1310,6 +1314,7 @@ impl File {
 
     #[cfg(any(
         target_os = "freebsd",
+	target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "linux",
         target_os = "netbsd",
@@ -1331,6 +1336,7 @@ impl File {
 
     #[cfg(not(any(
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "linux",
         target_os = "netbsd",
@@ -1346,6 +1352,7 @@ impl File {
 
     #[cfg(any(
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "linux",
         target_os = "netbsd",
@@ -1367,6 +1374,7 @@ impl File {
 
     #[cfg(not(any(
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "linux",
         target_os = "netbsd",
@@ -1382,6 +1390,7 @@ impl File {
 
     #[cfg(any(
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "linux",
         target_os = "netbsd",
@@ -1395,6 +1404,7 @@ impl File {
 
     #[cfg(not(any(
         target_os = "freebsd",
+        target_os = "dragonfly",
         target_os = "fuchsia",
         target_os = "linux",
         target_os = "netbsd",
