--- src/path.rs.orig	2025-10-07 20:56:06 UTC
+++ src/path.rs
@@ -732,8 +732,8 @@ pub fn path_remoteness(path: &wstr) -> D
         #[cfg(not(target_os = "netbsd"))]
         let remoteness = remoteness_via_statfs(
             libc::statfs,
-            |stat: &libc::statfs| stat.f_flags,
-            crate::libc::MNT_LOCAL(),
+            |stat: &libc::statfs| stat.f_flags as u64,
+            crate::libc::MNT_LOCAL() as u64,
             &narrow,
         );
         remoteness
