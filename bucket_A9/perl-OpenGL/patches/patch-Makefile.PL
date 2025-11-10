Don't check current display for extensions, build all.
Similar to gentoo portage.

--- Makefile.PL.orig	2025-04-14 04:33:29 UTC
+++ Makefile.PL
@@ -181,8 +181,7 @@ WriteMakefile(
       "lib/OpenGL/Config.pm ".
       "gl_exclude.h ".
       "utils/glversion.txt ".
-      "utils/glversion$Config{exe_ext} ".
-      "utils/glversion$Config{obj_ext}"
+      ""
   },
   %$build_config,
   INC => $INCS . ' -I'.curdir(),
@@ -504,47 +503,7 @@ sub get_gldata {
     ($found->{FREEGLUT32} || $found->{FREEGLUT}) ? "GLUT_DEF=HAVE_FREEGLUT " :
     ($found->{GLUT32} || $found->{GLUT}) ? "GLUT_DEF=HAVE_GLUT " :
     '';
-  # Platform-specific makefiles for glversion
-  my $make_ver;
-  my $append = " LIB='$libs' INC='$incs' DEF='$defs'";
-  if ($IS_STRAWBERRY) {
-    $make_ver = "&strawberry.bat";
-    print "strawberry glversion: '$make_ver'\n" if $verbose>1;
-  } elsif ($IS_MINGW) {
-    $make_ver = "&mingw.bat";
-    print "mingw glversion: '$make_ver'\n" if $verbose>1;
-  } elsif ($IS_W32API) {
-    $make_ver = ";make -f Makefile.cygwin $append";
-    print "cygwin glversion: '$make_ver'\n" if $verbose>1;
-  } elsif ($^O eq 'MSWin32') {
-    $make_ver = '&nmake -f makefile.mak ' . $append;
-    print "MSWin32 glversion: '$make_ver'\n" if $verbose>1;
-  } else {
-    $make_ver = ";make -f Makefile $append";
-    print "glversion: '$make_ver'\n" if $verbose>1;
-  }
-  my $exec = 'cd utils'."$make_ver clean".$make_ver;
-  print "glversion: $exec\n" if $verbose;
-  my $stat = `$exec`;
-  die "Error building glversion.txt: $stat" if $?;
-  print "\n$stat\n\n" if $verbose;
-  unlink "utils/freeglut.dll" or die "could not remove temporary freeglut: $!" if -f "utils/freeglut.dll";
-  # Parse glversion.txt file
-  open GLDATA, $glv_file or die "get_gldata: could not open $glv_file: $!\n";
   my $gldata = {};
-  my @gldata = <GLDATA>;
-  close(GLDATA);
-  foreach my $line (@gldata) {
-    $line =~ s|[\r\n]+||;
-    my($key,$val) = split('=',$line);
-    $gldata->{$key} = $val;
-  }
-  die "get_gldata: no extensions found in $glv_file\n" if !keys %$gldata;
-  print "This looks like OpenGL Version: $gldata->{VERSION}\n";
-  if ($^O eq 'darwin') {
-    $gldata->{VERSION} = '4.1';
-    print "  for MacOS X, overriding to version $gldata->{VERSION}\n";
-  }
   # Fix GLUT flags based on results
   if ($gldata->{FREEGLUT}) {
     print 'Found FreeGLUT v'.$gldata->{FREEGLUT}."\n";
@@ -570,12 +529,10 @@ sub generate_excl {
     next if ($ext =~ m|^GL_VERSION_|);
     $no_ext->{$ext}++;
   }
+
+  my $gldata = { };
   # Create gl_exclude.h
   die "Unable to write to $exc_file\n" if !open my $excl_fh, ">", $exc_file;
-  print $excl_fh "// OpenGL Extension Exclusions - may be modified before building.\n";
-  print $excl_fh "//\n";
-  print $excl_fh "// Generated for ".$gldata->{VENDOR}.", ".$gldata->{RENDERER}."\n";
-  print $excl_fh "// OpenGL v".$gldata->{VERSION}.", using ";
   print $excl_fh 'FreeGLUT v'.$gldata->{FREEGLUT}."\n" if $gldata->{FREEGLUT};
   my $GL_VERSION = $gldata->{VERSION} =~ m|^(\d\.\d+)| ? $1 : undef;
   # Make an empty exclusion file if a Windows distribution build
