--- lib/readline/rlprivate.h.orig	2025-03-07 23:51:02 UTC
+++ lib/readline/rlprivate.h
@@ -457,6 +457,8 @@ extern void _rl_sigwinch_resize_terminal
 extern int _rl_init_terminal_io (const char *);
 #ifdef _MINIX
 extern void _rl_output_character_function (int);
+#elif defined __sun__
+extern int _rl_output_character_function (char);
 #else
 extern int _rl_output_character_function (int);
 #endif
