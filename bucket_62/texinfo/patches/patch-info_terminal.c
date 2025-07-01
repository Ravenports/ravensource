--- info/terminal.c.orig	Tue Jul  1 20:08:05 2025
+++ info/terminal.c	Tue Jul  1 20:11:15 2025
@@ -151,11 +151,19 @@
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
