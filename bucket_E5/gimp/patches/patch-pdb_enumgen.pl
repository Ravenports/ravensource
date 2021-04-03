Should be ok.
--- pdb/enumgen.pl.orig	2021-03-28 21:52:56 UTC
+++ pdb/enumgen.pl
@@ -211,7 +211,7 @@ while (<>) {
        \*/@@gx;
 
     if (m@^\s*typedef\s+enum\s*
-	   ({)?\s*
+	   (\{)?\s*
 	   (?:/\*<
 	     (([^*]|\*(?!/))*)
 	    >\s*\*/)?
