--- source/dialogs/combi.c.orig	2021-08-29 09:11:37 UTC
+++ source/dialogs/combi.c
@@ -39,6 +39,15 @@
 #include <pango/pango.h>
 #include <theme.h>
 
+#ifdef __sun__
+static inline char *strchrnul(const char *s, int c)
+{
+	while (*s && *s != c)
+		s++;
+	return (char *)s;
+}
+#endif
+
 /**
  * Combi Mode
  */
