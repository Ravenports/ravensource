--- maskgen.c.orig	2016-10-22 12:40:44 UTC
+++ maskgen.c
@@ -16,7 +16,7 @@ extern int CODEPAGE;
 extern struct CODEPAGE_struct CP[CODEPAGES][CPSIZE];
 
 extern unsigned D_endpos, endposition, Init1, wildmask;
-extern Mask[], Bit[], Init[], NO_ERR_MASK;
+extern int Mask[], Bit[], Init[], NO_ERR_MASK;
 extern int AND, REGEX, NOUPPER, D_length;
 extern unsigned char Progname[];
 extern int agrep_initialfd;
