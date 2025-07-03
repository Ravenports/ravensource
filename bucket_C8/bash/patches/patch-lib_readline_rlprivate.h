--- lib/readline/rlprivate.h.orig	Thu Jul  3 06:05:24 2025
+++ lib/readline/rlprivate.h	Thu Jul  3 11:27:57 2025
@@ -406,6 +406,8 @@
 extern int _rl_init_terminal_io (const char *);
 #ifdef _MINIX
 extern void _rl_output_character_function (int);
+#elif defined __sun__
+extern int _rl_output_character_function (char);
 #else
 extern int _rl_output_character_function (int);
 #endif
