--- cargo-crates/linkme-0.3.27/src/distributed_slice.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/linkme-0.3.27/src/distributed_slice.rs
@@ -165,6 +165,8 @@ impl<T> DistributedSlice<[T]> {
         target_os = "illumos",
         target_os = "freebsd",
         target_os = "openbsd",
+        target_os = "netbsd",
+        target_os = "dragonfly",
         target_os = "psp",
     ))]
     pub const unsafe fn private_new(
