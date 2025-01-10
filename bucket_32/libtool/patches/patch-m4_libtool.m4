--- m4/libtool.m4.orig	2024-11-20 19:01:08 UTC
+++ m4/libtool.m4
@@ -2699,7 +2699,7 @@ darwin* | rhapsody*)
   version_type=darwin
   need_lib_prefix=no
   need_version=no
-  library_names_spec='$libname$release$major$shared_ext $libname$shared_ext'
+  library_names_spec='$libname$release$versuffix$shared_ext $libname$release$major$shared_ext $libname$shared_ext'
   soname_spec='$libname$release$major$shared_ext'
   shlibpath_overrides_runpath=yes
   shlibpath_var=DYLD_LIBRARY_PATH
