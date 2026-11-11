Disable assertions always

--- src/cpp.c.orig	2026-11-03 14:29:47 UTC
+++ src/cpp.c
@@ -2733,7 +2733,7 @@ static int parse_opt(int argc, char *arg
 	char *filename = 0;
 	int with_std_incpath = 1;
 	int print_version = 0, print_defs = 0, print_asserts = 0;
-	int system_macros = 0, standard_assertions = 1;
+	int system_macros = 0, standard_assertions = 0;
 
 	init_lexer_state(ls);
 	ls->flags = DEFAULT_CPP_FLAGS;
