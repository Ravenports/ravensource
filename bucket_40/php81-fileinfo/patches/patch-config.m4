--- config.m4.orig	2023-01-31 15:13:17 UTC
+++ config.m4
@@ -4,6 +4,9 @@ PHP_ARG_ENABLE([fileinfo],
     [Disable fileinfo support])],
   [yes])
 
+PHP_ARG_WITH(pcre-dir, pcre install prefix,
+[  --with-pcre-dir           FILEINFO: pcre install prefix], no, no)
+
 if test "$PHP_FILEINFO" != "no"; then
 
   libmagic_sources=" \
@@ -49,6 +52,8 @@ int main(void)
     libmagic_sources="$libmagic_sources libmagic/strcasestr.c"
   ],[AC_MSG_RESULT([skipped, cross-compiling])])
 
+  PHP_ADD_INCLUDE($PHP_PCRE_DIR/include)
+
   PHP_NEW_EXTENSION(fileinfo, fileinfo.c $libmagic_sources, $ext_shared,,-I@ext_srcdir@/libmagic)
   PHP_ADD_BUILD_DIR($ext_builddir/libmagic)
 
