--- cargo-crates/linkme-impl-0.3.27/src/declaration.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/linkme-impl-0.3.27/src/declaration.rs
@@ -127,31 +127,33 @@ pub fn expand(input: TokenStream) -> Tok
                 target_os = "illumos",
                 target_os = "freebsd",
                 target_os = "openbsd",
+                target_os = "netbsd",
+                target_os = "dragonfly",
                 target_os = "psp",
             ))]
             extern "Rust" {
                 #[cfg_attr(any(target_os = "none", target_os = "linux", target_os = "android", target_os = "fuchsia", target_os = "psp"), link_name = #linux_section_start)]
                 #[cfg_attr(any(target_os = "macos", target_os = "ios", target_os = "tvos"), link_name = #macho_section_start)]
                 #[cfg_attr(target_os = "illumos", link_name = #illumos_section_start)]
-                #[cfg_attr(any(target_os = "freebsd", target_os = "openbsd"), link_name = #bsd_section_start)]
+                #[cfg_attr(any(target_os = "freebsd", target_os = "openbsd", target_os = "dragonfly", target_os = "netbsd"), link_name = #bsd_section_start)]
                 static LINKME_START: <#ty as #linkme_path::__private::Slice>::Element;
 
                 #[cfg_attr(any(target_os = "none", target_os = "linux", target_os = "android", target_os = "fuchsia", target_os = "psp"), link_name = #linux_section_stop)]
                 #[cfg_attr(any(target_os = "macos", target_os = "ios", target_os = "tvos"), link_name = #macho_section_stop)]
                 #[cfg_attr(target_os = "illumos", link_name = #illumos_section_stop)]
-                #[cfg_attr(any(target_os = "freebsd", target_os = "openbsd"), link_name = #bsd_section_stop)]
+                #[cfg_attr(any(target_os = "freebsd", target_os = "openbsd", target_os = "dragonfly", target_os = "netbsd"), link_name = #bsd_section_stop)]
                 static LINKME_STOP: <#ty as #linkme_path::__private::Slice>::Element;
 
                 #[cfg_attr(any(target_os = "none", target_os = "linux", target_os = "android", target_os = "fuchsia", target_os = "psp"), link_name = #linux_dupcheck_start)]
                 #[cfg_attr(any(target_os = "macos", target_os = "ios", target_os = "tvos"), link_name = #macho_dupcheck_start)]
                 #[cfg_attr(target_os = "illumos", link_name = #illumos_dupcheck_start)]
-                #[cfg_attr(any(target_os = "freebsd", target_os = "openbsd"), link_name = #bsd_dupcheck_start)]
+                #[cfg_attr(any(target_os = "freebsd", target_os = "openbsd", target_os = "dragonfly", target_os = "netbsd"), link_name = #bsd_dupcheck_start)]
                 static DUPCHECK_START: #linkme_path::__private::usize;
 
                 #[cfg_attr(any(target_os = "none", target_os = "linux", target_os = "android", target_os = "fuchsia", target_os = "psp"), link_name = #linux_dupcheck_stop)]
                 #[cfg_attr(any(target_os = "macos", target_os = "ios", target_os = "tvos"), link_name = #macho_dupcheck_stop)]
                 #[cfg_attr(target_os = "illumos", link_name = #illumos_dupcheck_stop)]
-                #[cfg_attr(any(target_os = "freebsd", target_os = "openbsd"), link_name = #bsd_dupcheck_stop)]
+                #[cfg_attr(any(target_os = "freebsd", target_os = "openbsd", target_os = "dragonfly", target_os = "netbsd"), link_name = #bsd_dupcheck_stop)]
                 static DUPCHECK_STOP: #linkme_path::__private::usize;
             }
 
@@ -180,11 +182,13 @@ pub fn expand(input: TokenStream) -> Tok
                 target_os = "illumos",
                 target_os = "freebsd",
                 target_os = "openbsd",
+                target_os = "netbsd",
+                target_os = "dragonfly",
                 target_os = "psp",
             ))]
             #[cfg_attr(any(target_os = "none", target_os = "linux", target_os = "android", target_os = "fuchsia", target_os = "psp"), link_section = #linux_section)]
             #[cfg_attr(target_os = "illumos", link_section = #illumos_section)]
-            #[cfg_attr(any(target_os = "freebsd", target_os = "openbsd"), link_section = #bsd_section)]
+            #[cfg_attr(any(target_os = "freebsd", target_os = "openbsd", target_os = "dragonfly", target_os = "netbsd"), link_section = #bsd_section)]
             static mut LINKME_PLEASE: [<#ty as #linkme_path::__private::Slice>::Element; 0] = [];
 
             #used
@@ -192,7 +196,7 @@ pub fn expand(input: TokenStream) -> Tok
             #[cfg_attr(any(target_os = "macos", target_os = "ios", target_os = "tvos"), link_section = #macho_dupcheck)]
             #[cfg_attr(target_os = "windows", link_section = #windows_dupcheck)]
             #[cfg_attr(target_os = "illumos", link_section = #illumos_dupcheck)]
-            #[cfg_attr(any(target_os = "freebsd", target_os = "openbsd"), link_section = #bsd_dupcheck)]
+            #[cfg_attr(any(target_os = "freebsd", target_os = "openbsd", target_os = "dragonfly", target_os = "netbsd"), link_section = #bsd_dupcheck)]
             static DUPCHECK: #linkme_path::__private::usize = 1;
 
             #[cfg(not(any(
@@ -207,6 +211,8 @@ pub fn expand(input: TokenStream) -> Tok
                 target_os = "illumos",
                 target_os = "freebsd",
                 target_os = "openbsd",
+                target_os = "netbsd",
+                target_os = "dragonfly",
                 target_os = "psp",
             )))]
             #unsupported_platform
@@ -256,7 +262,7 @@ pub fn expand(input: TokenStream) -> Tok
                 #[cfg_attr(any(target_os = "macos", target_os = "ios", target_os = "tvos"), link_section = $macho_section)]
                 #[cfg_attr(target_os = "windows", link_section = $windows_section)]
                 #[cfg_attr(target_os = "illumos", link_section = $illumos_section)]
-                #[cfg_attr(any(target_os = "freebsd", target_os = "openbsd"), link_section = $bsd_section)]
+                #[cfg_attr(any(target_os = "freebsd", target_os = "openbsd", target_os = "dragonfly", target_os = "netbsd"), link_section = $bsd_section)]
                 $item
             };
             ($item:item) => {
@@ -265,7 +271,7 @@ pub fn expand(input: TokenStream) -> Tok
                 #[cfg_attr(any(target_os = "macos", target_os = "ios", target_os = "tvos"), link_section = #macho_section)]
                 #[cfg_attr(target_os = "windows", link_section = #windows_section)]
                 #[cfg_attr(target_os = "illumos", link_section = #illumos_section)]
-                #[cfg_attr(any(target_os = "freebsd", target_os = "openbsd"), link_section = #bsd_section)]
+                #[cfg_attr(any(target_os = "freebsd", target_os = "openbsd", target_os = "dragonfly", target_os = "netbsd"), link_section = #bsd_section)]
                 $item
             };
         }
