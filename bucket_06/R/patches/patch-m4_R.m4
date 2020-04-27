--- m4/R.m4.orig	2020-03-26 23:02:35 UTC
+++ m4/R.m4
@@ -3969,7 +3969,7 @@ case "${host_os}" in
   darwin*)
     R_SYSTEM_ABI="osx"
     ;;
-  freebsd*)
+  dragonfly*|freebsd*)
     R_SYSTEM_ABI="freebsd"
     ;;
   *)
