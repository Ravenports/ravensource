--- info/terminal.c.orig	2026-03-01 17:03:26 UTC
+++ info/terminal.c
@@ -154,11 +154,19 @@ char *term_me;
    return its argument, all the code I've looked at (termutils, less)
    does so, so fine.  */
 static int
+#if defined(__sun__)
+output_character_function (char c)
+{
+  putc ((int)c, stdout);
+  return (int)c;
+}
+#else
 output_character_function (int c)
 {
   putc (c, stdout);
   return c;
 }
+#endif
 
 /* Macro to send STRING to the terminal. */
 #define send_to_terminal(string) \
