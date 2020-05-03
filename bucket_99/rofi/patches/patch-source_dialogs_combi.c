--- source/dialogs/combi.c.orig	2019-07-01 12:29:09 UTC
+++ source/dialogs/combi.c
@@ -40,6 +40,15 @@
 #include "mode-private.h"
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
