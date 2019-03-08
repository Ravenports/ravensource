--- ext/ODBM_File/Makefile.PL.orig	2018-03-01 12:19:32 UTC
+++ ext/ODBM_File/Makefile.PL
@@ -4,4 +4,5 @@ WriteMakefile(
     LIBS => ["-ldbm -lucb"],
     XSPROTOARG => '-noprototypes', 		# XXX remove later?
     VERSION_FROM => 'ODBM_File.pm', 
+    dynamic_lib => { OTHERLDFLAGS => "-Wl,-rpath,@PREFIX@/lib" },
 );
