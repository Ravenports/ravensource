--- cargo-crates/tokio-1.44.2/src/io/poll_evented.rs.orig	2025-04-29 04:32:32 UTC
+++ cargo-crates/tokio-1.44.2/src/io/poll_evented.rs
@@ -206,6 +206,7 @@ feature! {
                                 // kqueue
                                 target_os = "dragonfly",
                                 target_os = "freebsd",
+                                target_os = "dragonfly",
                                 target_os = "ios",
                                 target_os = "macos",
                                 target_os = "netbsd",
