--- src/bitmap/pcfread.c.orig	2017-11-28 14:28:56 UTC
+++ src/bitmap/pcfread.c
@@ -47,6 +47,18 @@ from The Open Group.
 #include <stdint.h>
 #include <string.h>
 
+#ifdef __sun__
+static size_t
+strnlen(const char *s, size_t maxlen)
+{
+	size_t len;
+	for (len = 0; len < maxlen; len++, s++) {
+		if (!*s) break;
+	}
+	return (len);
+}
+#endif
+
 void
 pcfError(const char* message, ...)
 {
