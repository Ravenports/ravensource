--- main.c.orig	2018-07-13 09:16:01 UTC
+++ main.c
@@ -34,6 +34,10 @@ struct mgwin	*curwp;				/* current windo
 struct mgwin	*wheadp;			/* MGWIN listhead	*/
 char		 pat[NPAT];			/* pattern		*/
 
+#ifndef __dead
+#define __dead __attribute__ ((__noreturn__))
+#endif
+
 static void	 edinit(struct buffer *);
 static __dead void usage(void);
 
