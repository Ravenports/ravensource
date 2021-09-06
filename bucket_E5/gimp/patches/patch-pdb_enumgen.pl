Should be ok.
--- pdb/enumgen.pl.orig	2021-09-05 21:59:42 UTC
+++ pdb/enumgen.pl
@@ -211,7 +211,7 @@ while (<>) {
        \*/@@gx;
 
     if (m@^\s*typedef\s+enum\s*
-	   ({)?\s*
+	   (\{)?\s*
 	   (?:/\*<
 	     (([^*]|\*(?!/))*)
 	    >\s*\*/)?
