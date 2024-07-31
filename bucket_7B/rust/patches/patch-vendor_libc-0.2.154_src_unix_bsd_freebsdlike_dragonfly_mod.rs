--- vendor/libc-0.2.154/src/unix/bsd/freebsdlike/dragonfly/mod.rs.orig	2006-07-24 01:21:28 UTC
+++ vendor/libc-0.2.154/src/unix/bsd/freebsdlike/dragonfly/mod.rs
@@ -442,8 +442,8 @@ s_no_extra_traits! {
         pub d_fileno: ::ino_t,
         pub d_namlen: u16,
         pub d_type: u8,
-        __unused1: u8,
-        __unused2: u32,
+	pub d_unused1: u8,
+	pub d_unused2: u32,
         pub d_name: [::c_char; 256],
     }
 
@@ -1522,6 +1522,11 @@ pub const NGROUPS: usize = 16;
 pub const RB_PAUSE: ::c_int = 0x40000;
 pub const RB_VIDEO: ::c_int = 0x20000000;
 
+// For getrandom()
+pub const GRND_NONBLOCK: ::c_uint = 0x1;
+pub const GRND_RANDOM: ::c_uint = 0x2;
+pub const GRND_INSECURE: ::c_uint = 0x4;
+
 const_fn! {
     {const} fn _CMSG_ALIGN(n: usize) -> usize {
         (n + (::mem::size_of::<::c_long>() - 1)) & !(::mem::size_of::<::c_long>() - 1)
@@ -1658,6 +1663,7 @@ extern "C" {
         -> ::c_int;
     pub fn sched_getcpu() -> ::c_int;
     pub fn setproctitle(fmt: *const ::c_char, ...);
+    pub fn getrandom(buf: *mut ::c_void, buflen: ::size_t, flags: ::c_uint) -> ::ssize_t;
 
     pub fn shmget(key: ::key_t, size: ::size_t, shmflg: ::c_int) -> ::c_int;
     pub fn shmat(shmid: ::c_int, shmaddr: *const ::c_void, shmflg: ::c_int) -> *mut ::c_void;
