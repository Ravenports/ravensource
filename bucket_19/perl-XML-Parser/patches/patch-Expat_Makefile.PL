--- Expat/Makefile.PL.orig	2014-12-11 06:51:11 UTC
+++ Expat/Makefile.PL
@@ -7,7 +7,7 @@ my @extras = ();
 
 push(@extras, INC => "-I$expat_incpath") if $expat_incpath;
 
-$libs = "-L$expat_libpath $libs" if $expat_libpath;
+$libs = "-L$expat_libpath -Wl,-rpath,$expat_libpath -Wl,-rpath,@PERL_RPATH@ $libs" if $expat_libpath;
 
 push(@extras, CAPI => 'TRUE')
     if (($PERL_VERSION >= 5.005) and ($OSNAME eq 'MSWin32')
