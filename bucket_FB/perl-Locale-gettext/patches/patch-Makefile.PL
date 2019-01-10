--- Makefile.PL.orig	2015-09-18 17:06:07 UTC
+++ Makefile.PL
@@ -11,8 +11,8 @@ my $libs = '';
 
 unless (conftest("char *x = gettext(\"foo\");", "gettext", 0)) {
 	# try with -lintl
-	$libs = "-lintl";
-	unless (conftest("char *x = gettext(\"foo\");", "gettext", 0)) {
+	$libs = "-L$ENV{LOCALBASE}/lib -lintl -I$ENV{LOCALBASE}/include";
+	unless (conftest("#include <libintl.h>\nchar *x = gettext(\"foo\");", "gettext", 0)) {
 		unlink("conftest.c");
 		unlink("conftest");
 		die "gettext function not found. Please install libintl";
@@ -33,7 +33,8 @@ unlink("conftest");
 
 WriteMakefile(
     NAME => "Locale::gettext",
-    LIBS => ($libs eq '') ? [] : [$libs],
+    LIBS => ($libs eq '') ? [] : ["-L$ENV{LOCALBASE}/lib -lintl"],
+    INC => "-I$ENV{LOCALBASE}/include",
     VERSION_FROM => 'gettext.pm', 
     META_MERGE => {
         resources => {
