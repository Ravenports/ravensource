--- source/dialogs/combi.c.orig	2022-01-24 15:48:21 UTC
+++ source/dialogs/combi.c
@@ -40,6 +40,15 @@
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
