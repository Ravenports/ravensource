--- parse.y.orig	2023-01-09 11:20:17 UTC
+++ parse.y
@@ -44,7 +44,7 @@ ARRAY_DECL(, struct rule *) parse_rulest
 struct rule	*parse_rule;
 
 struct files	 parse_filestack;
-struct file	*parse_file;
+struct fdm_file	*parse_file;
 
 int		 yyparse(void);
 
