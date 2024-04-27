--- cargo-crates/linkme-0.3.8/src/distributed_slice.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/linkme-0.3.8/src/distributed_slice.rs
@@ -162,6 +162,8 @@ impl<T> DistributedSlice<[T]> {
         target_os = "ios",
         target_os = "tvos",
         target_os = "illumos",
+        target_os = "dragonfly",
+        target_os = "netbsd",
         target_os = "freebsd"
     ))]
     pub const unsafe fn private_new(
