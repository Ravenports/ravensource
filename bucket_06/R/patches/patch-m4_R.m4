--- m4/R.m4.orig	2023-04-04 22:15:01 UTC
+++ m4/R.m4
@@ -4203,7 +4203,7 @@ case "${host_os}" in
   darwin*)
     R_SYSTEM_ABI="macos"
     ;;
-  freebsd*)
+  dragonfly*|freebsd*)
     R_SYSTEM_ABI="freebsd"
     ;;
   *)
