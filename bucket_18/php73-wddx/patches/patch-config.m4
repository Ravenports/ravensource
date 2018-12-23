--- config.m4.orig	2017-08-01 17:36:48 UTC
+++ config.m4
@@ -13,6 +13,9 @@ fi
 PHP_ARG_WITH(libexpat-dir, libexpat dir for WDDX,
 [  --with-libexpat-dir=DIR WDDX: libexpat dir for XMLRPC-EPI (deprecated)],no,no)
 
+PHP_ARG_WITH(libxml-dir, libxml2 install dir,
+[  --with-libxml-dir=<DIR>    WDDX: libxml2 install prefix], no, no)
+
 if test "$PHP_WDDX" != "no"; then
 
   dnl
@@ -57,4 +60,9 @@ if test "$PHP_WDDX" != "no"; then
   PHP_NEW_EXTENSION(wddx, wddx.c, $ext_shared)
   PHP_ADD_EXTENSION_DEP(wddx, libxml)
   PHP_SUBST(XMLRPC_SHARED_LIBADD)
+
+  PHP_SETUP_LIBXML(WDDX_SHARED_LIBADD, [
+  ], [
+    AC_MSG_ERROR([xml2-config not found. Please check your libxml2 installation.])
+  ])
 fi
