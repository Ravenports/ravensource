--- pgdispd/proccom.c.orig	1994-08-22 20:33:35 UTC
+++ pgdispd/proccom.c
@@ -92,8 +92,9 @@ static char rcsid[]="@(#)$Id: proccom.c,
 #include <stdio.h>
 #include <sys/types.h>
 #include <netinet/in.h>
+#include <stdlib.h>
 
-#ifndef VMS
+#if !defined(VMS) && !defined(__FreeBSD__) && !defined(__DragonFly__)
 #include <values.h>
 #endif
 
@@ -163,8 +164,6 @@ int *retbuflen;	/* the length of retbuf
 	void drawline();	/* draw a line in the bitmap window */
 	Pixmap XCreatePixmap();
 
-	char *malloc();
-
 	if (!len & savedshorts)
 	{ /* an incomplete command was sent! */
 		savedshorts=0;
