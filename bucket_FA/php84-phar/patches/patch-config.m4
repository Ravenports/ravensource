--- config.m4.orig	2025-09-23 14:14:32 UTC
+++ config.m4
@@ -35,7 +35,7 @@ if test "$PHP_PHAR" != "no"; then
   PHP_INSTALL_HEADERS([ext/phar], [php_phar.h])
 
   AC_CONFIG_FILES([
-    $ext_dir/phar.1
-    $ext_dir/phar.phar.1
+    phar.1
+    phar.phar.1
   ])
 fi
