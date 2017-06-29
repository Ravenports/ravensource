--- lib/Padre/Locker.pm.orig	2013-11-09 03:43:41 UTC
+++ lib/Padre/Locker.pm
@@ -102,7 +102,6 @@ sub shutdown {
 sub db_increment {
 	my $self = shift;
 	unless ( $self->{db_depth}++ ) {
-		Padre::DB->begin;
 
 		# Database operations we lock on are the most likely to
 		# involve writes. So opportunistically prevent blocking
@@ -111,6 +110,7 @@ sub db_increment {
 		# corruption if (and only if) there is a power outage,
 		# operating system crash, or catastrophic hardware failure.
 		Padre::DB->pragma( synchronous => 0 );
+		Padre::DB->begin;
 	}
 	return;
 }
