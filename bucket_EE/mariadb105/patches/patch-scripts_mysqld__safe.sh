--- scripts/mysqld_safe.sh.orig	2025-04-25 16:21:42 UTC
+++ scripts/mysqld_safe.sh
@@ -559,11 +559,11 @@ fi
 
 if test -z "$MYSQL_HOME"
 then
-  if test -r "$DATADIR/my.cnf"
+  if test -r "$DATADIR/etc/my.cnf"
   then
     log_error "WARNING: Found $DATADIR/my.cnf
 The data directory is not a valid location for my.cnf, please move it to
-$MY_BASEDIR_VERSION/my.cnf"
+$MY_BASEDIR_VERSION/etc/my.cnf"
   fi
   MYSQL_HOME=$MY_BASEDIR_VERSION
 fi
