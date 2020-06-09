--- sapi/fpm/config.m4.orig	2020-06-09 08:06:31 UTC
+++ sapi/fpm/config.m4
@@ -319,7 +319,7 @@ AC_DEFUN([AC_FPM_LQ],
     AC_MSG_RESULT([no])
   ])
 
-  if test "$have_lq" = "tcp_info"; then
+  if test "$have_lq" = "so_listenq"; then
     AC_DEFINE([HAVE_LQ_TCP_INFO], 1, [do we have TCP_INFO?])
   fi
 
