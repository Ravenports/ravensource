--- m4/R.m4.orig	2021-04-19 22:02:02 UTC
+++ m4/R.m4
@@ -4089,7 +4089,7 @@ case "${host_os}" in
   darwin*)
     R_SYSTEM_ABI="macos"
     ;;
-  freebsd*)
+  dragonfly*|freebsd*)
     R_SYSTEM_ABI="freebsd"
     ;;
   *)
