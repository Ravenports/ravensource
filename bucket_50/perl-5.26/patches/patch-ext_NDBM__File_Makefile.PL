--- ext/NDBM_File/Makefile.PL.orig	2018-03-01 12:20:33 UTC
+++ ext/NDBM_File/Makefile.PL
@@ -4,5 +4,6 @@ WriteMakefile(
     LIBS => ["-L/usr/local/lib -lndbm", "-ldbm -lucb"],
     XSPROTOARG => '-noprototypes', 		# XXX remove later?
     VERSION_FROM => 'NDBM_File.pm',
+    dynamic_lib => { OTHERLDFLAGS => "-Wl,-rpath,@PREFIX@/lib" },
     INC => ($^O eq "MacOS" ? "-i ::::db:include" : "")
 );
