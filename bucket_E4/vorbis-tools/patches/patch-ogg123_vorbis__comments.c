--- ogg123/vorbis_comments.c.orig	2025-04-13 06:11:17 UTC
+++ ogg123/vorbis_comments.c
@@ -74,7 +74,7 @@ char *lookup_comment_prettyprint (const
 
   /* Use default formatting */
   j = strcspn(comment, "=");
-  if (j) {
+  if (j != strlen(comment)) {
     *offset = j + 1;
     s = malloc(j + 2);
     if (s == NULL) {
