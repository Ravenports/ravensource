--- cpan/ExtUtils-MakeMaker/lib/ExtUtils/Liblist/Kid.pm.orig	2018-03-23 19:34:31 UTC
+++ cpan/ExtUtils-MakeMaker/lib/ExtUtils/Liblist/Kid.pm
@@ -70,7 +70,7 @@ sub _unix_os2_ext {
             }
             my ( $rtype ) = $ptype;
             if ( ( $ptype eq '-R' ) or ( $ptype =~ m!^-Wl,-[Rr]! ) ) {
-                if ( $Config{'lddlflags'} =~ /-Wl,-[Rr]/ ) {
+                if ( $Config{'lddlflags'} =~ /-Wl,-[R]/ ) {
                     $rtype = '-Wl,-R';
                 }
                 elsif ( $Config{'lddlflags'} =~ /-R/ ) {
