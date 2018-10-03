--- m4/libtool.m4.orig	2015-01-20 16:15:19 UTC
+++ m4/libtool.m4
@@ -2636,7 +2636,7 @@ darwin* | rhapsody*)
   version_type=darwin
   need_lib_prefix=no
   need_version=no
-  library_names_spec='$libname$release$major$shared_ext $libname$shared_ext'
+  library_names_spec='$libname$release$versuffix$shared_ext $libname$release$major$shared_ext $libname$shared_ext'
   soname_spec='$libname$release$major$shared_ext'
   shlibpath_overrides_runpath=yes
   shlibpath_var=DYLD_LIBRARY_PATH
