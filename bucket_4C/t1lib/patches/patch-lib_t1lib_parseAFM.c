--- lib/t1lib/parseAFM.c.orig	2007-12-23 16:49:42.000000000 +0100
+++ lib/t1lib/parseAFM.c	2019-06-06 15:53:38.250925000 +0200
@@ -199,7 +199,7 @@
     idx = 0;
     
     while (ch != EOF && ch != ' ' && ch != CR  && ch != LF &&
-	   ch != CTRL_Z && ch != '\t' && ch != ':' && ch != ';'){
+	   ch != CTRL_Z && ch != '\t' && ch != ':' && ch != ';' && idx < (MAX_NAME - 1)){
       ident[idx++] = ch;
       ch = fgetc(stream);
     } /* while */
@@ -235,7 +235,7 @@
     while ((ch = fgetc(stream)) == ' ' || ch == '\t' ); 
     
     idx = 0;
-    while (ch != EOF && ch != CR  && ch != LF && ch != CTRL_Z) 
+    while (ch != EOF && ch != CR  && ch != LF && ch != CTRL_Z && idx < (MAX_NAME - 1)) 
     {
         ident[idx++] = ch;
         ch = fgetc(stream);
