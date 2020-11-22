--- scripts/mysql_config.sh.orig	2020-11-09 21:59:49 UTC
+++ scripts/mysql_config.sh
@@ -106,7 +106,9 @@ fi
 
 # Create options 
 libs="-L$pkglibdir @RPATH_OPTION@ @LIBS_FOR_CLIENTS@"
+libs="$libs -L%%LOCALBASE%%/lib "
 embedded_libs="-L$pkglibdir @RPATH_OPTION@ @EMB_LIBS_FOR_CLIENTS@"
+embedded_libs="$embedded_libs -L%%LOCALBASE%%/lib "
 
 include="-I$pkgincludedir"
 if [ "$basedir" != "/usr" ]; then
