--- m4/R.m4.orig	2026-08-10 15:15:01 UTC
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
