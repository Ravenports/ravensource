--- vendor/rustix/src/imp/libc/process/types.rs.orig	2023-01-10 22:12:01 UTC
+++ vendor/rustix/src/imp/libc/process/types.rs
@@ -197,6 +197,7 @@ pub enum Signal {
         target_os = "macos",
         target_os = "netbsd",
         target_os = "openbsd",
+        target_os = "dragonfly",
         all(
             any(target_os = "android", target_os = "linux"),
             any(target_arch = "mips", target_arch = "mips64"),
@@ -239,6 +240,7 @@ pub enum Signal {
         target_os = "macos",
         target_os = "netbsd",
         target_os = "openbsd",
+        target_os = "dragonfly",
     )))]
     #[doc(alias = "Pwr")]
     Power = c::SIGPWR,
@@ -274,6 +276,7 @@ impl Signal {
                 target_os = "macos",
                 target_os = "netbsd",
                 target_os = "openbsd",
+                target_os = "dragonfly",
                 all(
                     any(target_os = "android", target_os = "linux"),
                     any(target_arch = "mips", target_arch = "mips64"),
@@ -299,6 +302,7 @@ impl Signal {
                 target_os = "macos",
                 target_os = "netbsd",
                 target_os = "openbsd",
+                target_os = "dragonfly",
             )))]
             c::SIGPWR => Some(Self::Power),
             c::SIGSYS => Some(Self::Sys),
