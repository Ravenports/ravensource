--- lang/sql/sqlite/src/shell.c.orig	2013-09-09 15:35:06 UTC
+++ lang/sql/sqlite/src/shell.c
@@ -73,7 +73,7 @@
 #else
 /* Make sure isatty() has a prototype.
 */
-extern int isatty();
+extern int isatty(int);
 #endif
 
 #if defined(_WIN32_WCE)
