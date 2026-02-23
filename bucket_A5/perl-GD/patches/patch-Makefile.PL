--- Makefile.PL.orig	2026-01-04 19:38:13 UTC
+++ Makefile.PL
@@ -236,11 +236,6 @@ if ($^O eq 'VMS'){
   @LIBS    = qw(-llibgd.olb -llibpng.olb -llibz.olb);
 }
 
-# workaround for solaris and other systems
-elsif ($^O =~ /(solaris|hpux)/i) {
-    push @LIBS,'-liconv';
-}
-
 ###################################################################
 # path to libgd, skip prompt if passed in from above
 ###################################################################
