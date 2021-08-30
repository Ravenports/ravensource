--- ld/deffilep.c.orig	2021-07-18 16:48:53 UTC
+++ ld/deffilep.c
@@ -222,6 +222,8 @@ static const char *lex_parse_string_end
 extern int yydebug;
 #endif
 
+#undef SHARED
+
 /* Token type.  */
 #ifndef YYTOKENTYPE
 # define YYTOKENTYPE
