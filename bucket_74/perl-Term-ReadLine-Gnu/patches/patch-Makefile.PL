--- Makefile.PL.orig	2021-02-23 05:51:07 UTC
+++ Makefile.PL
@@ -100,6 +100,7 @@ if ($Config{osname} eq 'os2') {
     # Old Cygwin may require setting false (0).
     # tinfo is for Debian. [Debian Bug Report #644423]
     my $PREFER_CURSES = $Config{osname} eq 'aix' || $Config{osname} eq 'hpux'
+                        || $Config{osname} eq 'solaris'
 			|| $Config{osname} eq 'cygwin';
     my $TERMCAP_LIB = (! $PREFER_CURSES && &search_lib('-ltermcap'))
 	|| &search_lib('-ltinfo')
