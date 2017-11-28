--- ld/deffilep.c.orig	2017-09-15 12:42:05 UTC
+++ ld/deffilep.c
@@ -204,6 +204,8 @@ static const char *lex_parse_string_end
 extern int yydebug;
 #endif
 
+#undef SHARED
+
 /* Token type.  */
 #ifndef YYTOKENTYPE
 # define YYTOKENTYPE
