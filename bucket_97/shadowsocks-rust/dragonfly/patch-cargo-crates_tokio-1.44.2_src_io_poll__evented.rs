--- cargo-crates/tokio-1.45.0/src/io/poll_evented.rs.orig	2025-05-12 00:10:42 UTC
+++ cargo-crates/tokio-1.45.0/src/io/poll_evented.rs
@@ -206,6 +206,7 @@ feature! {
                                 // kqueue
                                 target_os = "dragonfly",
                                 target_os = "freebsd",
+                                target_os = "dragonfly",
                                 target_os = "ios",
                                 target_os = "macos",
                                 target_os = "netbsd",
