--- vendor/libc/src/unix/bsd/freebsdlike/dragonfly/mod.rs.orig	2023-08-03 13:47:24 UTC
+++ vendor/libc/src/unix/bsd/freebsdlike/dragonfly/mod.rs
@@ -442,8 +442,8 @@ s_no_extra_traits! {
         pub d_fileno: ::ino_t,
         pub d_namlen: u16,
         pub d_type: u8,
-        __unused1: u8,
-        __unused2: u32,
+        pub d_unused1: u8,
+        pub d_unused2: u32,
         pub d_name: [::c_char; 256],
     }
 
