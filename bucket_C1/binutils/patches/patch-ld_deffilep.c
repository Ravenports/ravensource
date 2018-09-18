--- ld/deffilep.c.orig	2018-06-24 18:50:57 UTC
+++ ld/deffilep.c
@@ -204,6 +204,8 @@ static const char *lex_parse_string_end
 extern int yydebug;
 #endif
 
+#undef SHARED
+
 /* Token type.  */
 #ifndef YYTOKENTYPE
 # define YYTOKENTYPE
