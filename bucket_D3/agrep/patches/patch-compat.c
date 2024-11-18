--- compat.c.orig	2016-10-22 12:40:44 UTC
+++ compat.c
@@ -8,13 +8,13 @@
 
 extern int D;
 extern int FILENAMEONLY, APPROX, PAT_FILE, PAT_BUFFER, MULTI_OUTPUT, COUNT, INVERSE, BESTMATCH;
-extern FILEOUT;
-extern REGEX;
-extern DELIMITER;
-extern WHOLELINE;
-extern LINENUM;
-extern I, S, DD;
-extern JUMP;
+extern int FILEOUT;
+extern int REGEX;
+extern int DELIMITER;
+extern int WHOLELINE;
+extern int LINENUM;
+extern int I, S, DD;
+extern int JUMP;
 extern char Progname[32];
 extern int agrep_initialfd;
 extern int EXITONERROR;
