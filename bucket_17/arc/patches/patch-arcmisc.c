--- arcmisc.c.orig	2013-06-27 02:00:19 UTC
+++ arcmisc.c
@@ -224,9 +224,12 @@ upper(string)
 			*p = toupper(*p);
 }
 /* VARARGS1 */
-VOID
+int
 arcdie(s, arg1, arg2, arg3)
 	char           *s;
+	int		arg1;
+	int		arg2;
+	int		arg3;
 {
 	fprintf(stderr, "ARC: ");
 	fprintf(stderr, s, arg1, arg2, arg3);
