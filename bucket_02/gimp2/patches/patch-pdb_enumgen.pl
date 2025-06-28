Should be ok.
--- pdb/enumgen.pl.orig	2024-05-03 00:33:35 UTC
+++ pdb/enumgen.pl
@@ -211,7 +211,7 @@ while (<>) {
        \*/@@gx;
 
     if (m@^\s*typedef\s+enum\s*
-	   ({)?\s*
+	   (\{)?\s*
 	   (?:/\*<
 	     (([^*]|\*(?!/))*)
 	    >\s*\*/)?
