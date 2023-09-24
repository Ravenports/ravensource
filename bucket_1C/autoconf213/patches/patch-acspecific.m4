--- acspecific.m4.orig	1999-01-05 13:27:52 UTC
+++ acspecific.m4
@@ -2659,7 +2659,7 @@ else
   if AC_TRY_EVAL(ac_link); then
     for file in conftest.*; do
       case $file in
-      *.c | *.o | *.obj) ;;
+      *.c | *.C | *.o | *.obj) ;;
       *) ac_cv_exeext=`echo $file | sed -e s/conftest//` ;;
       esac
     done
