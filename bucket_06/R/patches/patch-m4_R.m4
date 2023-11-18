--- m4/R.m4.orig	2023-07-29 22:15:01 UTC
+++ m4/R.m4
@@ -4242,7 +4242,7 @@ case "${host_os}" in
   darwin*)
     R_SYSTEM_ABI="macos"
     ;;
-  freebsd*)
+  dragonfly*|freebsd*)
     R_SYSTEM_ABI="freebsd"
     ;;
   *)
