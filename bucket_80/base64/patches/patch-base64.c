--- base64.c.orig	2007-06-10 15:00:59 UTC
+++ base64.c
@@ -63,13 +63,7 @@ static int iocp= MAXINLINE;
 static int ateof= FALSE;
 static byte dtable[256];
 static int linelength= 0;
-static char eol[]= 
-#ifdef FORCE_BINARY_IO
-"\n"
-#else
-"\r\n"
-#endif
-;
+static char eol[]="\n"; 
 static int errcheck= TRUE;
 
 /*:5*/
