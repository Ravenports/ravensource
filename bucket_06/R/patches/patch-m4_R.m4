--- m4/R.m4.orig	2019-09-06 22:15:02 UTC
+++ m4/R.m4
@@ -3973,7 +3973,7 @@ case "${host_os}" in
   darwin*)
     R_SYSTEM_ABI="osx"
     ;;
-  freebsd*)
+  dragonfly*|freebsd*)
     R_SYSTEM_ABI="freebsd"
     ;;
   *)
