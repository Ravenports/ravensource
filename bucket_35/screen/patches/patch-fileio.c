--- fileio.c.orig	2019-10-01 22:08:00 UTC
+++ fileio.c
@@ -480,10 +480,7 @@ void WriteFile(struct acluser *user, cha
                 break;
 
             case DUMP_TERMCAP:
-              if ((p = index(MakeTermcap(fore->w_aflag), '=')) != NULL) {
-                fputs(++p, f);
-                putc('\n', f);
-              }
+              DumpTermcap(fore->w_aflag, f);
 	      break;
 
 #ifdef COPY_PASTE
