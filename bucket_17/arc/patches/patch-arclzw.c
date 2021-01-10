--- arclzw.c.orig	2013-06-27 02:00:19 UTC
+++ arclzw.c
@@ -558,7 +558,7 @@ decomp(squash, f, t)		/* decompress a fi
 		 */
 		if (code >= free_ent) {
 			if (code > free_ent) {
-				if (warn) {
+				if (arcwarn) {
 					printf("Corrupted compressed file.\n");
 					printf("Invalid code %d when max is %d.\n",
 					       code, free_ent);
