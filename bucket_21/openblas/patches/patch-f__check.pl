--- f_check.pl.orig	2026-04-23 11:50:46 UTC
+++ f_check.pl
@@ -322,13 +322,8 @@ $linker_a = "";
 
 if ($link ne "") {
 
-    $link =~ s/\-Y\sP\,/\-Y/g;
-    
-    $link =~ s/\-R\s*/\-rpath\%/g;
-
-    $link =~ s/\-rpath\s+/\-rpath\%/g;
-
-    $link =~ s/\-rpath-link\s+/\-rpath-link\%/g;
+    # Delete -Y, any whitespace, and the following path string until the next whitespace
+    $link =~ s/-Y\s*P,[^\s]*//g;
 
     @flags = split(/[\s\,\n]/, $link);
     # remove leading and trailing quotes from each flag.
