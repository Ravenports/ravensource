--- arclzw.c.orig	2013-06-27 02:00:19 UTC
+++ arclzw.c
@@ -56,8 +56,7 @@ static VOID     putcode();
 
 extern u_char	*pinbuf;
 u_char		*inbeg, *inend;
-u_char          *outbuf;
-u_char          *outbeg, *outend; 
+u_char          *outbeg; 
 
 static int      sp;		/* current stack pointer */
 static int	inflag;
@@ -558,7 +557,7 @@ decomp(squash, f, t)		/* decompress a fi
 		 */
 		if (code >= free_ent) {
 			if (code > free_ent) {
-				if (warn) {
+				if (arcwarn) {
 					printf("Corrupted compressed file.\n");
 					printf("Invalid code %d when max is %d.\n",
 					       code, free_ent);
