--- cpan/DB_File/Makefile.PL.orig	2019-10-21 11:20:36 UTC
+++ cpan/DB_File/Makefile.PL
@@ -51,6 +51,7 @@ WriteMakefile(
 	INC		=> "-I$INC_DIR",
     VERSION_FROM	=> 'DB_File.pm',
 	XS_VERSION      => eval MM->parse_version('DB_File.pm'),
+        dynamic_lib     => { OTHERLDFLAGS => "-L@WRKSRC@" },
 	XSPROTOARG	=> '-noprototypes',
 	DEFINE		=> "$CORE $OS2 $VER_INFO $COMPAT185 $WALL",
 	OBJECT		=> 'version$(OBJ_EXT) DB_File$(OBJ_EXT)',
