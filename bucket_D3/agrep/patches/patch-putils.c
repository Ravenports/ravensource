--- putils.c.orig	2016-10-22 12:40:44 UTC
+++ putils.c
@@ -68,6 +68,7 @@ get_token_bool(buffer, len, ptr, tokenbu
 void
 print_tree(t, level)
 	ParseTree *t;
+	int level;
 {
 	int	i;
 
