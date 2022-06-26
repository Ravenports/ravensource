--- m4/R.m4.orig	2022-04-03 22:15:01 UTC
+++ m4/R.m4
@@ -4080,7 +4080,7 @@ case "${host_os}" in
   darwin*)
     R_SYSTEM_ABI="macos"
     ;;
-  freebsd*)
+  dragonfly*|freebsd*)
     R_SYSTEM_ABI="freebsd"
     ;;
   *)
