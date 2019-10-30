--- extern.h.orig	2019-10-01 22:08:00 UTC
+++ extern.h
@@ -235,6 +235,7 @@ extern int   StuffKey __P((int));
 /* termcap.c */
 extern int   InitTermcap __P((int, int));
 extern char *MakeTermcap __P((int));
+extern void  DumpTermcap __P((int, FILE *));
 extern char *gettermcapstring __P((char *));
 #ifdef MAPKEYS
 extern int   remap __P((int, int));
