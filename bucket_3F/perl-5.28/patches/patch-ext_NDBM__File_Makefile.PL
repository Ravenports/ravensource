--- ext/NDBM_File/Makefile.PL.orig	2018-11-01 22:07:48 UTC
+++ ext/NDBM_File/Makefile.PL
@@ -4,4 +4,5 @@ WriteMakefile(
     LIBS => ["-L/usr/local/lib -lndbm", "-ldbm -lucb"],
     XSPROTOARG => '-noprototypes', 		# XXX remove later?
     VERSION_FROM => 'NDBM_File.pm',
+    dynamic_lib => { OTHERLDFLAGS => "-Wl,-rpath,@PREFIX@/lib" },
 );
