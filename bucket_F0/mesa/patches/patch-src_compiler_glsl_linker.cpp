--- src/compiler/glsl/linker.cpp.orig	2018-01-18 21:30:28 UTC
+++ src/compiler/glsl/linker.cpp
@@ -87,6 +87,38 @@
 #include "main/shaderobj.h"
 #include "main/enums.h"
 
+#ifdef __sun__
+/* uses libbsd4sol prototypes, so can't be static */
+#include <stdlib.h>
+#include <stdint.h>
+#include <string.h>
+
+size_t
+strnlen(const char *s, size_t maxlen)
+{
+	size_t len;
+	for (len = 0; len < maxlen; len++, s++) {
+		if (!*s) break;
+	}
+	return (len);
+}
+
+char *
+strndup(const char *str, size_t n)
+{
+    size_t len;
+    char *copy;
+
+    len = strlen(str);
+    if (len <= n)
+        return strdup(str);
+    if ((copy = (char *)malloc(len + 1)) == NULL)
+        return (NULL);
+    memcpy(copy, str, len);
+    copy[len] = '\0';
+    return (copy);
+}
+#endif
 
 namespace {
 
