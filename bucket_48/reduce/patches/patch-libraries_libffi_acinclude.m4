--- libraries/libffi/acinclude.m4.orig	2021-03-13 09:18:00 UTC
+++ libraries/libffi/acinclude.m4
@@ -382,7 +382,7 @@ if test x$enable_symvers = xyes ; then
     else
       case ${target_os} in
         # Sun symbol versioning exists since Solaris 2.5.
-        solaris2.[[5-9]]* | solaris2.1[[0-9]]*)
+        skip)
           enable_symvers=sun ;;
         *)
           enable_symvers=no ;;
