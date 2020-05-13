--- scripts/mysqld_safe.sh.orig	2020-05-09 22:11:44 UTC
+++ scripts/mysqld_safe.sh
@@ -562,11 +562,11 @@ fi
 
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
