--- Modules/nismodule.c.orig	2025-04-08 11:35:47 UTC
+++ Modules/nismodule.c
@@ -116,7 +116,7 @@ nis_mapname(char *map, int *pfix)
     return map;
 }
 
-#if defined(__APPLE__) || defined(__OpenBSD__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__DragonFly__)
 typedef int (*foreachfunc)(unsigned long, char *, int, char *, int, void *);
 #else
 typedef int (*foreachfunc)(int, char *, int, char *, int, char *);
