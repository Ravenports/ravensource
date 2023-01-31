From ce30bd97bc2be67532f94f9d9c41a2ab0914b3e1 Mon Sep 17 00:00:00 2001
From: Dan Gohman <dev@sunfishcode.online>
Date: Thu, 1 Dec 2022 11:03:27 -0800
Subject: [PATCH] Don't check the `errno` value from `isatty`. (#468)

We don't actually do anything different for different errno values,
other than panic on unknown ones, and that isn't that isn't adding
much value compared to the cost of being an extra surprise when
porting to new OS's.

Fixes #467.

--- vendor/rustix/src/backend/libc/termios/syscalls.rs.orig	2023-01-25 01:49:17 UTC
+++ vendor/rustix/src/backend/libc/termios/syscalls.rs
@@ -10,11 +10,11 @@ use crate::fd::BorrowedFd;
 #[cfg(feature = "procfs")]
 #[cfg(not(any(target_os = "fuchsia", target_os = "wasi")))]
 use crate::ffi::CStr;
+#[cfg(not(target_os = "wasi"))]
 use crate::io;
 use crate::process::{Pid, RawNonZeroPid};
 use crate::termios::{Action, OptionalActions, QueueSelector, Speed, Termios, Winsize};
 use core::mem::MaybeUninit;
-use libc_errno::errno;
 
 pub(crate) fn tcgetattr(fd: BorrowedFd<'_>) -> io::Result<Termios> {
     let mut result = MaybeUninit::<Termios>::uninit();
@@ -123,26 +123,12 @@ pub(crate) fn cfsetspeed(termios: &mut T
 }
 
 pub(crate) fn isatty(fd: BorrowedFd<'_>) -> bool {
-    let res = unsafe { c::isatty(borrowed_fd(fd)) };
-    if res == 0 {
-        match errno().0 {
-            #[cfg(not(any(target_os = "android", target_os = "linux")))]
-            c::ENOTTY => false,
-
-            // Old Linux versions reportedly return `EINVAL`.
-            // <https://man7.org/linux/man-pages/man3/isatty.3.html#ERRORS>
-            #[cfg(any(target_os = "android", target_os = "linux"))]
-            c::ENOTTY | c::EINVAL => false,
-
-            // Darwin mysteriously returns `EOPNOTSUPP` sometimes.
-            #[cfg(any(target_os = "ios", target_os = "macos"))]
-            c::EOPNOTSUPP => false,
-
-            err => panic!("unexpected error from isatty: {:?}", err),
-        }
-    } else {
-        true
-    }
+    // Use the return value of `isatty` alone. We don't check `errno` because
+    // we return `bool` rather than `io::Result<bool>`, because we assume
+    // `BorrrowedFd` protects us from `EBADF`, and any other reasonably
+    // anticipated errno value would end up interpreted as "assume it's not a
+    // terminal" anyway.
+    unsafe { c::isatty(borrowed_fd(fd)) != 0 }
 }
 
 #[cfg(feature = "procfs")]
