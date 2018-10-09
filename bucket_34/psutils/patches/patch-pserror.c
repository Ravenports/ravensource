--- pserror.c.orig	1997-03-11 22:53:01 UTC
+++ pserror.c
@@ -24,7 +24,7 @@ extern char *program ;	/* Defined by mai
 void message(int flags, char *format, ...)
 {
   va_list args ;
-  static column = 0 ;		/* current screen column for message wrap */
+  static int column = 0 ;		/* current screen column for message wrap */
   char msgbuf[MAX_MESSAGE] ;	/* buffer in which to put the message */
   char *bufptr = msgbuf ;	/* message buffer pointer */
 
