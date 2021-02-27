--- Po4aBuilder.pm.orig	2020-12-07 15:24:54 UTC
+++ Po4aBuilder.pm
@@ -118,8 +118,8 @@ sub ACTION_install {
     $mandir =~ s,/man3$,,;
     $self->install_path(man => $mandir);
 
-    my $localedir = $self->install_destination('libdoc');
-    $localedir =~ s,/man/man3$,/locale,;
+    my $localedir = $self->install_destination('bin');
+    $localedir =~ s,/bin$,/share/locale,;
     $self->install_path(po => $localedir);
 
     ExtUtils::Install::install($self->install_map, !$self->quiet, 0, $self->{args}{uninst}||0);
@@ -250,7 +250,7 @@ sub ACTION_man {
 		system("xsltproc -o $outdir/$outfile.$section --nonet /usr/share/xml/docbook/stylesheet/docbook-xsl/manpages/docbook.xsl $file") and die;
 	    } else { # Not found locally, use the XSL file online
 		print "Convert $outdir/$outfile.$section (online docbook.xsl file). ";
-		system("xsltproc -o $outdir/$outfile.$section --nonet http://docbook.sourceforge.net/release/xsl/current/manpages/docbook.xsl $file") and die;
+		system("xsltproc -o $outdir/$outfile.$section --nonet http://cdn.docbook.org/release/xsl/current/manpages/docbook.xsl $file") and die;
 	    }
             system ("gzip -9 -f $outdir/$outfile.$section") and die;
         }
