--- pgdispd/initlgwin.c.orig	1995-02-24 18:13:24 UTC
+++ pgdispd/initlgwin.c
@@ -34,6 +34,7 @@
 
 /* The system include files */
 #include <stdio.h>
+#include <stdlib.h>
 
 /* the X Window include files */
 #include <X11/Xlib.h>
@@ -67,7 +68,6 @@ int initlgwin()
 
 	Pixmap XCreatePixmap();
 	void initlgluts();	/* initialize the LUTs */
-	char *malloc();
 	void initwmattr();
 
 	/* Initialize the line graphics LUTs */
