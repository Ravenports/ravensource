--- m4/R.m4.orig	2021-01-17 23:15:01 UTC
+++ m4/R.m4
@@ -4083,7 +4083,7 @@ case "${host_os}" in
   darwin*)
     R_SYSTEM_ABI="macos"
     ;;
-  freebsd*)
+  dragonfly*|freebsd*)
     R_SYSTEM_ABI="freebsd"
     ;;
   *)
