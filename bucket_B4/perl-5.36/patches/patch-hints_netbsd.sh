--- hints/netbsd.sh.orig	2023-03-02 11:53:19 UTC
+++ hints/netbsd.sh
@@ -202,8 +202,8 @@ EOCBU
 # Set sensible defaults for NetBSD: look for local software in
 # /usr/pkg (NetBSD Packages Collection) and in /usr/local.
 #
-loclibpth="/usr/pkg/lib /usr/local/lib"
-locincpth="/usr/pkg/include /usr/local/include"
+loclibpth="/usr/local/lib"
+locincpth="/usr/local/include"
 case "$rpathflag" in
 '')
 	ldflags=
