--- hints/solaris_2.sh.orig	2017-07-18 22:50:01 UTC
+++ hints/solaris_2.sh
@@ -622,7 +622,6 @@ EOM
 		# use that with Solaris 11 and later, but keep
 		# the old behavior for older Solaris versions.
 		case "$osvers" in
-			2.?|2.10) lddlflags="$lddlflags -G -m64" ;;
 			*) lddlflags="$lddlflags -shared -m64" ;;
 		esac
 		;;
