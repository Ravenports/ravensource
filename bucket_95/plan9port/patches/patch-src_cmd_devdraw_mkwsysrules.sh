--- src/cmd/devdraw/mkwsysrules.sh.orig	2022-09-12 14:35:36 UTC
+++ src/cmd/devdraw/mkwsysrules.sh
@@ -24,7 +24,7 @@ fi
 
 if [ "x$WSYSTYPE" = "x" ]; then
 	if [ "x`uname`" = "xDarwin" ]; then
-		if sw_vers | egrep 'ProductVersion:	(10\.[0-9]\.|10\.1[012])$' >/dev/null; then
+		if sw_vers | grep -E 'ProductVersion:	(10\.[0-9]\.|10\.1[012])$' >/dev/null; then
 			echo 1>&2 'OS X 10.12 and older are not supported'
 			exit 1
 		fi
