--- lib/readline/terminal.c.orig	Thu Jul  3 06:06:42 2025
+++ lib/readline/terminal.c	Thu Jul  3 06:12:32 2025
@@ -697,6 +697,12 @@
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
