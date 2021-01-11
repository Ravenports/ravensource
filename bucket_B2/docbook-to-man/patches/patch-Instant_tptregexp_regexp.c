--- Instant/tptregexp/regexp.c.orig	1996-06-17 03:50:29 UTC
+++ Instant/tptregexp/regexp.c
@@ -196,7 +196,6 @@ char *exp;
 	register char *longest;
 	register int len;
 	int flags;
-	extern char *malloc();
 
 	if (exp == NULL)
 		FAIL("NULL argument");
@@ -705,7 +704,6 @@ register regexp *prog;
 register char *string;
 {
 	register char *s;
-	extern char *strchr();
 
 	/* Be paranoid... */
 	if (prog == NULL || string == NULL) {
@@ -804,7 +802,6 @@ char *prog;
 {
 	register char *scan;	/* Current node. */
 	char *next;		/* Next node. */
-	extern char *strchr();
 
 	scan = prog;
 #ifdef DEBUG
