--- src/bootstrap/src/core/build_steps/install.rs.orig	2026-03-25 01:22:28 UTC
+++ src/bootstrap/src/core/build_steps/install.rs
@@ -15,9 +15,9 @@ use crate::utils::helpers::t;
 use crate::utils::tarball::GeneratedTarball;
 use crate::{Compiler, Kind};
 
-#[cfg(target_os = "illumos")]
+#[cfg(any(target_os = "illumos", target_os = "netbsd"))]
 const SHELL: &str = "bash";
-#[cfg(not(target_os = "illumos"))]
+#[cfg(not(any(target_os = "illumos", target_os = "netbsd")))]
 const SHELL: &str = "sh";
 
 /// We have to run a few shell scripts, which choke quite a bit on both `\`
