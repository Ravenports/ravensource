--- cpan/DB_File/Makefile.PL.orig	2025-03-30 10:35:40 UTC
+++ cpan/DB_File/Makefile.PL
@@ -50,6 +50,7 @@ WriteMakefile(
         LIBS            => ["-L${LIB_DIR} $LIBS"],
         INC             => "-I$INC_DIR",
         VERSION_FROM    => 'DB_File.pm',
+        dynamic_lib     => { OTHERLDFLAGS => "-L@WRKSRC@" },
         XS_VERSION      => eval MM->parse_version('DB_File.pm'),
         XSPROTOARG      => '-noprototypes',
         DEFINE          => "$CORE $OS2 $VER_INFO $COMPAT185 $WALL",
