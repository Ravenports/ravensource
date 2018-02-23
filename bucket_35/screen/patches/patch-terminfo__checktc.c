--- terminfo/checktc.c.orig	2016-11-12 22:12:37 UTC
+++ terminfo/checktc.c
@@ -171,6 +171,7 @@ char *s;
   fflush(stdout);
 }
 
+#if !(defined __FreeBSD__ || defined __DragonFly__)
 void CPutStr(s, c)
 char *s;
 int c;
@@ -178,6 +179,7 @@ int c;
   tputs(tgoto(s, 0, c), 1, putcha);
   fflush(stdout);
 }
+#endif /* ! __FreeBSD__ or __DragonFly__ */
 
 void CCPutStr(s, x, y)
 char *s;
