--- m4/R.m4.orig	2025-03-13 23:02:02 UTC
+++ m4/R.m4
@@ -4603,7 +4603,7 @@ case "${host_os}" in
   darwin*)
     R_SYSTEM_ABI="macos"
     ;;
-  freebsd*)
+  dragonfly*|freebsd*)
     R_SYSTEM_ABI="freebsd"
     ;;
   *)
