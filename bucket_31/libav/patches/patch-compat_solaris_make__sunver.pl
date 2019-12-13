--- compat/solaris/make_sunver.pl.orig	2018-02-12 21:25:59 UTC
+++ compat/solaris/make_sunver.pl
@@ -200,7 +200,8 @@ printf "# Omitted archives with correspo
     (join ' ', @SHAREDOBJS) if $#SHAREDOBJS >= 0;
 print "#\n\n";
 
-print "\$mapfile_version 2\n";
+# solaris 10u8 only knows version 1
+# print "\$mapfile_version 2\n";
 
 while (<F>) {
     # Lines of the form '};'
@@ -232,7 +233,7 @@ while (<F>) {
     if (/^[ \t]*$/) { print; next; }
 
     # Lines of the form '{'
-    if (/^([ \t]*){$/) {
+    if (/^([ \t]*)\{$/) {
     if ($in_extern) {
         print "$1##{\n";
     } else {
@@ -248,7 +249,7 @@ while (<F>) {
     # Reset match attempts, #matched symbols for this version.
     $matches_attempted = 0;
     $matched_symbols = 0;
-    print "SYMBOL_VERSION $1 {\n";
+    print "$1 {\n";
     next;
     }
 
