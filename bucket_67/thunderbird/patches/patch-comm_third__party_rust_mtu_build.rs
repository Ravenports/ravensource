--- comm/third_party/rust/mtu/build.rs.orig	2025-04-12 05:14:10 UTC
+++ comm/third_party/rust/mtu/build.rs
@@ -103,6 +103,7 @@ fn main() {
                 target_os = "freebsd",
                 target_os = "openbsd",
                 target_os = "netbsd",
+                target_os = "dragonfly",
                 target_os = "solaris"
             )
         }
