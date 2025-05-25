--- terminfo/checktc.c.orig	2025-05-15 15:31:27 UTC
+++ terminfo/checktc.c
@@ -171,6 +171,7 @@ char *s;
   fflush(stdout);
 }
 
+#ifndef __FreeBSD__
 void CPutStr(s, c)
 char *s;
 int c;
@@ -178,6 +179,7 @@ int c;
   tputs(tgoto(s, 0, c), 1, putcha);
   fflush(stdout);
 }
+#endif /* __FreeBSD__ */
 
 void CCPutStr(s, x, y)
 char *s;
