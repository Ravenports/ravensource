--- parse.c.orig	2019-06-20 23:12:56 UTC
+++ parse.c
@@ -98,8 +98,11 @@ parse_make(
 
 	if( DEBUG_COMPILE && !p->left && !p->right )
 	{
+#pragma GCC diagnostic push
+#pragma GCC diagnostic ignored "-Wimplicit-function-declaration"
 	    p->yyfname = yyfname();
 	    p->yylineno = yylineno();
+#pragma GCC diagnostic pop
 	}
 
 	return p;
