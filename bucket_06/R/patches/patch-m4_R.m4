--- m4/R.m4.orig	2026-03-26 23:02:02 UTC
+++ m4/R.m4
@@ -4595,7 +4595,7 @@ case "${host_os}" in
   darwin*)
     R_SYSTEM_ABI="macos"
     ;;
-  freebsd*)
+  dragonfly*|freebsd*)
     R_SYSTEM_ABI="freebsd"
     ;;
   *)
