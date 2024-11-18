--- sgrep.c.orig	2016-10-22 12:40:44 UTC
+++ sgrep.c
@@ -97,7 +97,7 @@ extern int CONSTANT, COUNT, FNAME, SILEN
 extern int DNA ;	/* DNA flag is set in checksg when pattern is DNA pattern
 			   and p_size > 16  */
 
-extern WORDBOUND, WHOLELINE, NOUPPER;
+extern int WORDBOUND, WHOLELINE, NOUPPER;
 extern unsigned char CurrentFileName[],  Progname[]; 
 extern unsigned Mask[];
 extern unsigned endposition;
@@ -263,6 +263,7 @@ int sgrep(in_pat, in_m, fd, D, samepatte
 
 CHARTYPE *in_pat;  
 int fd, in_m, D;
+int samepattern;
 {
 	CHARTYPE patbuf[MAXLINE];
 	CHARTYPE *pat = patbuf;
@@ -1485,7 +1486,7 @@ CHARTYPE **lastout;	/* in, out */
 static void
 prep_bm(Pattern, m)      
 unsigned char *Pattern;
-register m;
+int register m;
 {
 	int i;
 	unsigned hash;
