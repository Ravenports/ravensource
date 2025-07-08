--- helpers/docbook2man-spec.pl.orig	2024-10-09 12:46:46 UTC
+++ helpers/docbook2man-spec.pl
@@ -7,7 +7,7 @@ docbook2man-spec - convert DocBook RefEn
 The SGMLSpm package from CPAN.  This contains the sgmlspl script which
 is used to grok this file.  Use it like this:
 
-nsgmls some-docbook-document.sgml | sgmlspl docbook2man-spec.pl
+onsgmls some-docbook-document.sgml | sgmlspl docbook2man-spec.pl
 
 =head1 DESCRIPTION
 
