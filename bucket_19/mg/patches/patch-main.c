--- main.c.orig	2018-09-28 18:34:33.627045000 +0300
+++ main.c	2018-09-28 18:34:57.797531000 +0300
@@ -35,7 +35,7 @@ struct mgwin	*wheadp;			/* MGWIN listhea
 char		 pat[NPAT];			/* pattern		*/
 
 #ifndef __dead
-#define __dead __dead2
+#define __dead __attribute__ ((__noreturn__))
 #endif
 
 static void	 edinit(struct buffer *);
