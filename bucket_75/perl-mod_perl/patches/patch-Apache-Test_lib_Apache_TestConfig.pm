--- Apache-Test/lib/Apache/TestConfig.pm.orig	2016-10-27 20:10:58 UTC
+++ Apache-Test/lib/Apache/TestConfig.pm
@@ -805,7 +805,7 @@ my $remote_addr;
 sub our_remote_addr {
     my $self = shift;
     my $name = $self->default_servername;
-    my $iaddr = (gethostbyname($name))[-1];
+    my $iaddr = Socket::inet_aton("127.0.0.1");
     unless (defined $iaddr) {
         error "Can't resolve host: '$name' (check /etc/hosts)";
         exit 1;
