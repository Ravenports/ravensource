--- vendor/rustix/src/imp/libc/fs/dir.rs.orig	2022-12-12 18:23:59 UTC
+++ vendor/rustix/src/imp/libc/fs/dir.rs
@@ -172,10 +172,10 @@ unsafe fn read_dirent(input: &libc_diren
     )))]
     let d_ino = input.d_ino;
 
-    #[cfg(any(target_os = "freebsd", target_os = "netbsd", target_os = "openbsd"))]
+    #[cfg(any(target_os = "freebsd", target_os = "netbsd", target_os = "openbsd", target_os = "dragonfly"))]
     let d_fileno = input.d_fileno;
 
-    #[cfg(not(target_os = "wasi"))]
+    #[cfg(not(any(target_os = "wasi", target_os = "dragonfly")))]
     let d_reclen = input.d_reclen;
 
     #[cfg(any(
@@ -184,12 +184,18 @@ unsafe fn read_dirent(input: &libc_diren
         target_os = "openbsd",
         target_os = "ios",
         target_os = "macos",
+        target_os = "dragonfly",
     ))]
     let d_namlen = input.d_namlen;
 
     #[cfg(any(target_os = "ios", target_os = "macos"))]
     let d_seekoff = input.d_seekoff;
 
+    #[cfg(target_os = "dragonfly")]
+    let d_unused1 = input.d_unused1;
+    #[cfg(target_os = "dragonfly")]
+    let d_unused2 = input.d_unused2;
+
     // Construct the input. Rust will give us an error if any OS has a input
     // with a field that we missed here. And we can avoid blindly copying the
     // whole `d_name` field, which may not be entirely allocated.
@@ -213,9 +219,9 @@ unsafe fn read_dirent(input: &libc_diren
             target_os = "openbsd",
         )))]
         d_ino,
-        #[cfg(any(target_os = "freebsd", target_os = "netbsd", target_os = "openbsd"))]
+        #[cfg(any(target_os = "freebsd", target_os = "netbsd", target_os = "openbsd", target_os = "dragonfly"))]
         d_fileno,
-        #[cfg(not(target_os = "wasi"))]
+        #[cfg(not(any(target_os = "wasi", target_os = "dragonfly")))]
         d_reclen,
         #[cfg(any(
             target_os = "freebsd",
@@ -223,10 +229,15 @@ unsafe fn read_dirent(input: &libc_diren
             target_os = "macos",
             target_os = "netbsd",
             target_os = "openbsd",
+            target_os = "dragonfly",
         ))]
         d_namlen,
         #[cfg(any(target_os = "ios", target_os = "macos"))]
         d_seekoff,
+        #[cfg(target_os = "dragonfly")]
+        d_unused1,
+        #[cfg(target_os = "dragonfly")]
+        d_unused2,
         // The `d_name` field is NUL-terminated, and we need to be careful not
         // to read bytes past the NUL, even though they're within the nominal
         // extent of the `struct dirent`, because they may not be allocated. So
