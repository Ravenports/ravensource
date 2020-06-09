--- cpan/DB_File/Makefile.PL.orig	2020-05-14 09:23:02 UTC
+++ cpan/DB_File/Makefile.PL
@@ -47,6 +47,7 @@ WriteMakefile(
 	INC		=> "-I$INC_DIR",
     VERSION_FROM	=> 'DB_File.pm',
 	XS_VERSION      => eval MM->parse_version('DB_File.pm'),
+        dynamic_lib     => { OTHERLDFLAGS => "-L@WRKSRC@" },
 	XSPROTOARG	=> '-noprototypes',
 	DEFINE		=> "-D_NOT_CORE $OS2 $VER_INFO $COMPAT185 $WALL",
 	OBJECT		=> 'version$(OBJ_EXT) DB_File$(OBJ_EXT)',
