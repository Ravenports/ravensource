--- cargo-crates/libc-0.2.174/src/unix/bsd/freebsdlike/dragonfly/mod.rs.orig	2025-07-20 23:55:03 UTC
+++ cargo-crates/libc-0.2.174/src/unix/bsd/freebsdlike/dragonfly/mod.rs
@@ -45,6 +45,21 @@ pub type vm_map_entry_t = *mut vm_map_en
 
 pub type pmap = __c_anonymous_pmap;
 
+pub type caddr_t = *mut c_char;
+
+pub const IP_BINDANY: c_int = 24;
+pub const IP_BINDMULTI: c_int = 25;
+pub const IP_RSS_LISTEN_BUCKET: c_int = 26;
+pub const IP_ORIGDSTADDR: c_int = 27;
+pub const IP_RECVORIGDSTADDR: c_int = IP_ORIGDSTADDR;
+
+pub const IP_DONTFRAG: c_int = 67;
+pub const IP_RECVTOS: c_int = 68;
+
+pub const IPV6_BINDANY: c_int = 64;
+pub const IPV6_ORIGDSTADDR: c_int = 72;
+pub const IPV6_RECVORIGDSTADDR: c_int = IPV6_ORIGDSTADDR;
+
 #[cfg_attr(feature = "extra_traits", derive(Debug))]
 pub enum sem {}
 impl Copy for sem {}
@@ -531,6 +546,35 @@ s_no_extra_traits! {
         pub uc_arg: *mut c_void,
         __pad: [c_int; 4],
     }
+
+    pub union __c_anonymous_ifr_ifru {
+        pub ifru_addr: crate::sockaddr,
+        pub ifru_dstaddr: crate::sockaddr,
+        pub ifru_broadaddr: crate::sockaddr,
+        pub ifru_buffer: ifreq_buffer,
+        pub ifru_flags: [c_short; 2],
+        pub ifru_index: c_short,
+        pub ifru_jid: c_int,
+        pub ifru_metric: c_int,
+        pub ifru_mtu: c_int,
+        pub ifru_phys: c_int,
+        pub ifru_media: c_int,
+        pub ifru_data: crate::caddr_t,
+        pub ifru_cap: [c_int; 2],
+        pub ifru_fib: c_uint,
+        pub ifru_vlan_pcp: c_uchar,
+    }
+
+    pub struct ifreq {
+        /// if name, e.g. "en0"
+        pub ifr_name: [c_char; crate::IFNAMSIZ],
+        pub ifr_ifru: __c_anonymous_ifr_ifru,
+    }
+
+    pub struct ifreq_buffer {
+        pub length: size_t,
+        pub buffer: *mut c_void,
+    }
 }
 
 cfg_if! {
