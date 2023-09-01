--- terminfo/checktc.c.orig	2023-08-16 00:29:26 UTC
+++ terminfo/checktc.c
@@ -171,6 +171,7 @@ char *s;
   fflush(stdout);
 }
 
+#if !defined(__FreeBSD__) && !defined(__DragonFly__)
 void CPutStr(s, c)
 char *s;
 int c;
@@ -178,6 +179,7 @@ int c;
   tputs(tgoto(s, 0, c), 1, putcha);
   fflush(stdout);
 }
+#endif /* __FreeBSD__ || __DragonFly__*/
 
 void CCPutStr(s, x, y)
 char *s;
