--- XS.xs.orig	2008-12-08 04:22:09 UTC
+++ XS.xs
@@ -418,7 +418,7 @@ result(pagerank p)
     Array * result;
     SV ** res;
   INIT:
-    results = (AV *)sv_2mortal((SV *)newAV());
+    results = (HV *)sv_2mortal((SV *)newAV());
   CODE:
     if (p->num_elements < 2)
       croak("Only one element in pagerank table.");
