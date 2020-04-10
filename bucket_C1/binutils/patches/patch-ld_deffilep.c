--- ld/deffilep.c.orig	2020-02-01 12:02:51 UTC
+++ ld/deffilep.c
@@ -205,6 +205,8 @@ static const char *lex_parse_string_end
 extern int yydebug;
 #endif
 
+#undef SHARED
+
 /* Token type.  */
 #ifndef YYTOKENTYPE
 # define YYTOKENTYPE
