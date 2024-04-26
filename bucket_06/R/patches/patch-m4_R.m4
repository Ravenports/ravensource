--- m4/R.m4.orig	2024-04-04 22:15:01 UTC
+++ m4/R.m4
@@ -4465,7 +4465,7 @@ case "${host_os}" in
   darwin*)
     R_SYSTEM_ABI="macos"
     ;;
-  freebsd*)
+  dragonfly*|freebsd*)
     R_SYSTEM_ABI="freebsd"
     ;;
   *)
