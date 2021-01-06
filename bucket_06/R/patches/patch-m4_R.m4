--- m4/R.m4.orig	2020-09-01 22:15:02 UTC
+++ m4/R.m4
@@ -3971,7 +3971,7 @@ case "${host_os}" in
   darwin*)
     R_SYSTEM_ABI="macos"
     ;;
-  freebsd*)
+  dragonfly*|freebsd*)
     R_SYSTEM_ABI="freebsd"
     ;;
   *)
