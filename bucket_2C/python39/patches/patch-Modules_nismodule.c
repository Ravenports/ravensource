--- Modules/nismodule.c.orig	2021-04-02 09:51:53 UTC
+++ Modules/nismodule.c
@@ -85,7 +85,7 @@ nis_mapname (char *map, int *pfix)
     return map;
 }
 
-#if defined(__APPLE__) || defined(__OpenBSD__) || defined(__FreeBSD__)
+#if defined(__APPLE__) || defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__DragonFly__)
 typedef int (*foreachfunc)(unsigned long, char *, int, char *, int, void *);
 #else
 typedef int (*foreachfunc)(int, char *, int, char *, int, char *);
