--- sapi/apache2handler/config.m4.orig	2025-09-23 14:14:32 UTC
+++ sapi/apache2handler/config.m4
@@ -69,7 +69,7 @@ if test "$PHP_APXS2" != "no"; then
     [AC_MSG_ERROR([Please note that Apache version >= 2.4 is required])])
 
   APXS_LIBEXECDIR='$(INSTALL_ROOT)'$($APXS -q LIBEXECDIR)
-  if test -z $($APXS -q SYSCONFDIR); then
+  if true; then
     INSTALL_IT="\$(mkinstalldirs) '$APXS_LIBEXECDIR' && \
                  $APXS -S LIBEXECDIR='$APXS_LIBEXECDIR' \
                        -i -n php"
