--- src/getopt.c.orig	2023-04-02 16:27:27 UTC
+++ src/getopt.c
@@ -566,7 +566,7 @@ _getopt_internal_r (int argc, char *cons
 		     || pfound->val != p->val)
 	      {
 		/* Second or later nonexact match found.  */
-		struct option_list *newp = alloca (sizeof (*newp));
+		struct option_list *newp = __builtin_alloca (sizeof (*newp));
 		newp->p = p;
 		newp->next = ambig_list;
 		ambig_list = newp;
