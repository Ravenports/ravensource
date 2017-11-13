--- acspecific.m4.orig	2017-11-13 13:29:43.063432000 +0100
+++ acspecific.m4	2017-11-13 13:30:37.762988000 +0100
@@ -2659,7 +2659,7 @@
   if AC_TRY_EVAL(ac_link); then
     for file in conftest.*; do
       case $file in
-      *.c | *.o | *.obj) ;;
+      *.c | *.C | *.o | *.obj) ;;
       *) ac_cv_exeext=`echo $file | sed -e s/conftest//` ;;
       esac
     done
