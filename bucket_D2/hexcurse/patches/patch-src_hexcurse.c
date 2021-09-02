--- src/hexcurse.c.orig	2015-11-18 04:33:09 UTC
+++ src/hexcurse.c
@@ -27,6 +27,8 @@
 /*#define DEBUG_LLIST*/
 /*#define DEBUG_GOTO*/
 
+FILE	*fpIN;
+
 int     BASE, MAXY, resize = 0;
 int     MIN_ADDR_LENGTH;
 hexList *head;						/* linked list struct */
