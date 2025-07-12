--- lib/readline/terminal.c.orig	2025-06-11 15:05:41 UTC
+++ lib/readline/terminal.c
@@ -809,6 +809,12 @@ _rl_output_character_function (int c)
 {
   putc (c, _rl_out_stream);
 }
+#elif defined(__sun__)
+int
+_rl_output_character_function (char c)
+{
+  return putc (c, _rl_out_stream);
+}
 #else /* !_MINIX */
 int
 _rl_output_character_function (int c)
