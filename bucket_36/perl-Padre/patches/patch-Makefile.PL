--- Makefile.PL.orig	2021-02-12 15:04:07 UTC
+++ Makefile.PL
@@ -54,20 +54,6 @@ configure_requires 'ExtUtils::Embed' =>
 #	exit 0;
 #}
 
-# This makes sure that we didn't compile Alien::wxWidgets with the wrong options.
-configure_requires 'Alien::wxWidgets' => '0.62';
-
-my $wxw = eval { use Alien::wxWidgets; 1; };
-if ( $@ or not $wxw ) {
-	print STDERR "Warning: prerequisite Alien::wxWidgets not found.\n";
-	exit 0;
-}
-if ( '2.009000' eq Alien::wxWidgets->version ) {
-	print STDERR "Warning: Alien::wxWidgets was compiled with the development version of\n";
-	print STDERR "wxWidgets. This is known to cause Padre to crash.\n";
-	exit 0;
-}
-
 
 
 
