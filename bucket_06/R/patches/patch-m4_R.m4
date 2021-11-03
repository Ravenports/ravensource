--- m4/R.m4.orig	2021-09-19 22:15:01 UTC
+++ m4/R.m4
@@ -4081,7 +4081,7 @@ case "${host_os}" in
   darwin*)
     R_SYSTEM_ABI="macos"
     ;;
-  freebsd*)
+  dragonfly*|freebsd*)
     R_SYSTEM_ABI="freebsd"
     ;;
   *)
