--- cpan/Pod-Perldoc/lib/Pod/Perldoc/ToMan.pm.orig	2018-11-01 22:07:31 UTC
+++ cpan/Pod-Perldoc/lib/Pod/Perldoc/ToMan.pm
@@ -108,6 +108,8 @@ sub _get_columns_from_manwidth {
 
 	return 0 unless defined $ENV{MANWIDTH};
 
+	if ($ENV{MANWIDTH} eq 'tty') { return 0; }
+
 	unless( $ENV{MANWIDTH} =~ m/\A\d+\z/ ) {
 		$self->warn( "Ignoring non-numeric MANWIDTH ($ENV{MANWIDTH})\n" );
 		return 0;
