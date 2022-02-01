Don't generate glversion.txt.  This requires working xorg server
which is not present.  A hardcoded version of the file is put in
place with another patch.

--- Makefile.PL.orig	2022-01-09 17:02:15 UTC
+++ Makefile.PL
@@ -121,14 +121,7 @@ if ($IS_MINGW)
 # Look for available libs
 our @libdirs = qw
 {
-  -L/usr/lib
-  -L/usr/lib/i386-linux-gnu
-  -L/usr/X11R6/lib
-  -L/opt/X11/lib
-  -L/usr/local/lib
-  -L/usr/openwin/lib
-  -L/opt/csw/lib
-  -L/usr/local/freeglut/lib
+  -L/raven/lib
 };
 
 our @check_libs = qw
@@ -805,7 +798,6 @@ sub get_extensions
   my $exc_file = 'gl_exclude.h';
   unlink($exc_file) if (-e $exc_file);
   my $glv_file = 'utils/glversion.txt';
-  unlink($glv_file) if (-e $glv_file);
 
   # Only run the rest if GLUT is installed
   print "Testing GLUT version\n" if ($verbose);
@@ -862,11 +854,8 @@ sub get_extensions
     $make_ver = ";make -f Makefile " .  (length($lib) ? "GLUT_LIB=$lib " : "") . (length($def) ? "GLUT_DEF=$def " : "");
     print "glversion: '$make_ver'\n" if $verbose>1;
   }
-  my $exec = 'cd utils'."$make_ver clean".$make_ver;
+  my $exec = 'cd utils'.$make_ver;
   print "glversion: $exec\n" if ($verbose);
-  my $stat = `$exec`;
-  print "\n$stat\n\n" if ($verbose);
-  unlink "utils/freeglut.dll" or die "could not remove temporary freeglut: $!" if -f "utils/freeglut.dll";
 
   # Parse glversion.txt file
   open GLDATA, $glv_file or die "get_extensions: could not open $glv_file: $!\n";
