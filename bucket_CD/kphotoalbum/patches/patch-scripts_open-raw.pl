--- scripts/open-raw.pl.orig	2025-01-06 10:49:15 UTC
+++ scripts/open-raw.pl
@@ -16,9 +16,16 @@ my @rawExt = (
 );
 
 # The application you use to develop the RAW files
-my @raw_converters = ( "/usr/bin/AfterShot2X64", "/usr/bin/AfterShot2",
+my @raw_converters = (
+	"/raven/bin/ART",
+	"/raven/bin/darktable",
+	"/usr/local/bin/rawtherapee",
+	"/usr/local/bin/darktable",
+	"/usr/local/bin/ufraw",
+	"/usr/bin/AfterShot2X64", "/usr/bin/AfterShot2",
 	"/usr/bin/AfterShotPro", "/usr/bin/bibble5",
-	"/usr/bin/ufraw", "/usr/bin/rt", "/usr/bin/darktable" );
+	"/usr/bin/ufraw", "/usr/bin/rt", "/usr/bin/darktable"
+	);
 my @ASP_work = ( "/usr/bin/AfterShot3X64" );
 my $extApp = "";
 my $workApp = "";
