--- cargo-crates/linkme-impl-0.3.8/src/declaration.rs.orig	2006-07-24 01:21:28 UTC
+++ cargo-crates/linkme-impl-0.3.8/src/declaration.rs
@@ -125,30 +125,32 @@ pub fn expand(input: TokenStream) -> Tok
                 target_os = "tvos",
                 target_os = "illumos",
                 target_os = "freebsd",
+		target_os = "dragonfly",
+		target_os = "netbsd",
             ))]
             extern "Rust" {
                 #[cfg_attr(any(target_os = "none", target_os = "linux"), link_name = #linux_section_start)]
                 #[cfg_attr(any(target_os = "macos", target_os = "ios", target_os = "tvos"), link_name = #macho_section_start)]
                 #[cfg_attr(target_os = "illumos", link_name = #illumos_section_start)]
-                #[cfg_attr(target_os = "freebsd", link_name = #freebsd_section_start)]
+                #[cfg_attr(any(target_os = "freebsd", target_os = "dragonfly", target_os = "netbsd"), link_name = #freebsd_section_start)]
                 static LINKME_START: <#ty as #linkme_path::__private::Slice>::Element;
 
                 #[cfg_attr(any(target_os = "none", target_os = "linux"), link_name = #linux_section_stop)]
                 #[cfg_attr(any(target_os = "macos", target_os = "ios", target_os = "tvos"), link_name = #macho_section_stop)]
                 #[cfg_attr(target_os = "illumos", link_name = #illumos_section_stop)]
-                #[cfg_attr(target_os = "freebsd", link_name = #freebsd_section_stop)]
+                #[cfg_attr(any(target_os = "freebsd", target_os = "dragonfly", target_os = "netbsd"), link_name = #freebsd_section_stop)]
                 static LINKME_STOP: <#ty as #linkme_path::__private::Slice>::Element;
 
                 #[cfg_attr(any(target_os = "none", target_os = "linux"), link_name = #linux_dupcheck_start)]
                 #[cfg_attr(any(target_os = "macos", target_os = "ios", target_os = "tvos"), link_name = #macho_dupcheck_start)]
                 #[cfg_attr(target_os = "illumos", link_name = #illumos_dupcheck_start)]
-                #[cfg_attr(target_os = "freebsd", link_name = #freebsd_dupcheck_start)]
+                #[cfg_attr(any(target_os = "freebsd", target_os = "dragonfly", target_os = "netbsd"), link_name = #freebsd_dupcheck_start)]
                 static DUPCHECK_START: #linkme_path::__private::usize;
 
                 #[cfg_attr(any(target_os = "none", target_os = "linux"), link_name = #linux_dupcheck_stop)]
                 #[cfg_attr(any(target_os = "macos", target_os = "ios", target_os = "tvos"), link_name = #macho_dupcheck_stop)]
                 #[cfg_attr(target_os = "illumos", link_name = #illumos_dupcheck_stop)]
-                #[cfg_attr(target_os = "freebsd", link_name = #freebsd_dupcheck_stop)]
+                #[cfg_attr(any(target_os = "freebsd", target_os = "dragonfly", target_os = "netbsd"), link_name = #freebsd_dupcheck_stop)]
                 static DUPCHECK_STOP: #linkme_path::__private::usize;
             }
 
@@ -169,10 +171,10 @@ pub fn expand(input: TokenStream) -> Tok
             static DUPCHECK_STOP: () = ();
 
             #used
-            #[cfg(any(target_os = "none", target_os = "linux", target_os = "illumos", target_os = "freebsd"))]
+            #[cfg(any(target_os = "none", target_os = "linux", target_os = "illumos", target_os = "freebsd", target_os = "dragonfly", target_os = "netbsd"))]
             #[cfg_attr(any(target_os = "none", target_os = "linux"), link_section = #linux_section)]
             #[cfg_attr(target_os = "illumos", link_section = #illumos_section)]
-            #[cfg_attr(target_os = "freebsd", link_section = #freebsd_section)]
+            #[cfg_attr(any(target_os = "freebsd", target_os = "dragonfly", target_os = "netbsd"), link_section = #freebsd_section)]
             static mut LINKME_PLEASE: [<#ty as #linkme_path::__private::Slice>::Element; 0] = [];
 
             #used
@@ -180,7 +182,7 @@ pub fn expand(input: TokenStream) -> Tok
             #[cfg_attr(any(target_os = "macos", target_os = "ios", target_os = "tvos"), link_section = #macho_dupcheck)]
             #[cfg_attr(target_os = "windows", link_section = #windows_dupcheck)]
             #[cfg_attr(target_os = "illumos", link_section = #illumos_dupcheck)]
-            #[cfg_attr(target_os = "freebsd", link_section = #freebsd_dupcheck)]
+            #[cfg_attr(any(target_os = "freebsd", target_os = "dragonfly", target_os = "netbsd"), link_section = #freebsd_dupcheck)]
             static DUPCHECK: #linkme_path::__private::usize = 1;
 
             #[cfg(not(any(
@@ -192,6 +194,8 @@ pub fn expand(input: TokenStream) -> Tok
                 target_os = "windows",
                 target_os = "illumos",
                 target_os = "freebsd",
+		target_os = "dragonfly",
+		target_os = "netbsd",
             )))]
             #unsupported_platform
 
@@ -240,7 +244,7 @@ pub fn expand(input: TokenStream) -> Tok
                 #[cfg_attr(any(target_os = "macos", target_os = "ios", target_os = "tvos"), link_section = $macho_section)]
                 #[cfg_attr(target_os = "windows", link_section = $windows_section)]
                 #[cfg_attr(target_os = "illumos", link_section = $illumos_section)]
-                #[cfg_attr(target_os = "freebsd", link_section = $freebsd_section)]
+                #[cfg_attr(any(target_os = "freebsd", target_os = "dragonfly", target_os = "netbsd"), link_section = $freebsd_section)]
                 $item
             };
             ($item:item) => {
@@ -249,7 +253,7 @@ pub fn expand(input: TokenStream) -> Tok
                 #[cfg_attr(any(target_os = "macos", target_os = "ios", target_os = "tvos"), link_section = #macho_section)]
                 #[cfg_attr(target_os = "windows", link_section = #windows_section)]
                 #[cfg_attr(target_os = "illumos", link_section = #illumos_section)]
-                #[cfg_attr(target_os = "freebsd", link_section = #freebsd_section)]
+                #[cfg_attr(any(target_os = "freebsd", target_os = "dragonfly", target_os = "netbsd"), link_section = #freebsd_section)]
                 $item
             };
         }
