--- vendor/libc-0.2.127/src/unix/bsd/freebsdlike/dragonfly/mod.rs.orig	2023-02-07 09:07:50 UTC
+++ vendor/libc-0.2.127/src/unix/bsd/freebsdlike/dragonfly/mod.rs
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
 
@@ -901,6 +901,7 @@ cfg_if! {
 
 pub const RAND_MAX: ::c_int = 0x7fff_ffff;
 pub const PTHREAD_STACK_MIN: ::size_t = 16384;
+pub const CPU_SETSIZE: ::c_int = 256;
 pub const SIGSTKSZ: ::size_t = 40960;
 pub const SIGCKPT: ::c_int = 33;
 pub const SIGCKPTEXIT: ::c_int = 34;
