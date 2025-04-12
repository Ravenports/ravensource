--- scripts/make.sh.orig	2025-04-12 06:25:50 UTC
+++ scripts/make.sh
@@ -129,8 +129,6 @@ then
     ;;
   mac_*)
     list="cslbuild/*${host}*/csl"
-    host1=${host/aarch64/universal}
-    host1=${host1/x86_64/universal}
     case "$list cslbuild/*${host1}*" in
     \*)
 # If there is a "*" still present that indicated that the "universal"
