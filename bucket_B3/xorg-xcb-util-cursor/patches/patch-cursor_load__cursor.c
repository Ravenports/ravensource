--- cursor/load_cursor.c.orig	2016-05-12 07:52:06 UTC
+++ cursor/load_cursor.c
@@ -44,6 +44,47 @@
 #include "cursor.h"
 #include "xcb_cursor.h"
 
+#ifdef __sun__
+#include <sys/varargs.h>
+static int
+vasprintf(char **strp, const char *fmt, va_list args)
+{
+    va_list args_copy;
+    int status, needed;
+
+    va_copy(args_copy, args);
+    needed = vsnprintf(NULL, 0, fmt, args_copy);
+    va_end(args_copy);
+    if (needed < 0) {
+        *strp = NULL;
+        return needed;
+    }
+    *strp = malloc(needed + 1);
+    if (*strp == NULL)
+        return -1;
+    status = vsnprintf(*strp, needed + 1, fmt, args);
+    if (status >= 0)
+        return status;
+    else {
+        free(*strp);
+        *strp = NULL;
+        return status;
+    }
+}
+
+static int
+asprintf(char **strp, const char *fmt, ...)
+{
+    va_list args;
+    int status;
+
+    va_start(args, fmt);
+    status = vasprintf(strp, fmt, args);
+    va_end(args);
+    return status;
+}
+#endif
+
 static const char *cursor_path(struct xcb_cursor_context_t *c) {
     if (c->path == NULL) {
         c->path = getenv("XCURSOR_PATH");
