--- Po4aBuilder.pm.orig	2018-12-09 16:27:11 UTC
+++ Po4aBuilder.pm
@@ -116,8 +116,8 @@ sub ACTION_install {
     $mandir =~ s,/man3$,,;
     $self->install_path(man => $mandir);
 
-    my $localedir = $self->install_destination('libdoc');
-    $localedir =~ s,/man/man3$,/locale,;
+    my $localedir = $self->install_destination('bin');
+    $localedir =~ s,/bin$,/share/locale,;
     $self->install_path(po => $localedir);
 
     ExtUtils::Install::install($self->install_map, !$self->quiet, 0, $self->{args}{uninst}||0);
@@ -244,7 +244,7 @@ sub ACTION_man {
     foreach $file (@{$self->rscan_dir($manpath, qr{\.xml$})}) {
         if ($file =~ m,(.*/man(.))/([^/]*)\.xml$,) {
             my ($outdir, $section, $outfile) = ($1, $2, $3);
-            system("xsltproc -o $outdir/$outfile.$section --nonet http://docbook.sourceforge.net/release/xsl/current/manpages/docbook.xsl $file") and die;
+            system("xsltproc -o $outdir/$outfile.$section --nonet http://cdn.docbook.org/release/xsl/current/manpages/docbook.xsl $file") and die;
             system ("gzip -9 -f $outdir/$outfile.$section") and die;
         }
         unlink "$file" || die;
