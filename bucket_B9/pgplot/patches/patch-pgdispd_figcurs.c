--- pgdispd/figcurs.c.orig	1993-11-29 19:55:24 UTC
+++ pgdispd/figcurs.c
@@ -21,6 +21,7 @@
 #include <stdio.h>
 #include <sys/types.h>
 #include <netinet/in.h>
+#include <stdlib.h>
 
 /* The X Window include files */
 #include <X11/Xlib.h>
@@ -113,8 +114,6 @@ XEvent event;
 	void getbuttonval();
 	int getkeyval();
 
-	char *malloc();
-
 	if (event.type == ButtonPress) getbuttonval(event.xbutton.button, &val);
 	else if (!getkeyval(event, &val)) return(1);
 
@@ -167,8 +166,6 @@ XEvent event;
 	void getbuttonval();
 	int getkeyval();
 
-	char *malloc();
-
 	if (event.type == ButtonPress) getbuttonval(event.xbutton.button, &val);
 	else if (!getkeyval(event, &val)) return(1);
 
