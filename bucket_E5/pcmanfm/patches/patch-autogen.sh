--- autogen.sh.orig	2025-03-04 11:58:51 UTC
+++ autogen.sh
@@ -4,19 +4,6 @@ AC_VERSION=
 AUTOMAKE=${AUTOMAKE:-automake}
 AM_INSTALLED_VERSION=$($AUTOMAKE --version | sed -e '2,$ d' -e 's/.* \([0-9]*\.[0-9]*\).*/\1/')
 
-# FIXME: we need a better way for version check later.
-case "$AM_INSTALLED_VERSION" in
-    1.1[0-9])
-	;;
-    *)
-	echo
-	echo "You must have automake 1.10 or newer installed."
-	echo "Install the appropriate package for your distribution,"
-	echo "or get the source tarball at http://ftp.gnu.org/gnu/automake/"
-	exit 1
-	;;
-esac
-
 set -x
 
 if [ "x${ACLOCAL_DIR}" != "x" ]; then
