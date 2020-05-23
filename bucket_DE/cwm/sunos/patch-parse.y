This needs to be regenerated -- will not apply

--- parse.y.orig	2020-01-04 20:45:17 UTC
+++ parse.y
@@ -22,10 +22,8 @@
 %{
 
 #include <sys/types.h>
-#include <sys/queue.h>
 
 #include <ctype.h>
-#include <err.h>
 #include <errno.h>
 #include <limits.h>
 #include <stdarg.h>
@@ -33,6 +31,49 @@
 #include <stdlib.h>
 #include <string.h>
 
+#ifdef __sun__
+#include <sys/varargs.h>
+
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
+        return (needed);
+    }
+    *strp = (char *)malloc(needed + 1);
+    if (*strp == NULL)
+        return (-1);
+    status = vsnprintf(*strp, needed + 1, fmt, args);
+    if (status >= 0)
+        return (status);
+    else {
+        free(*strp);
+        *strp = NULL;
+        return (status);
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
+    return (status);
+}
+#endif
+
+#include "queue.h"
 #include "calmwm.h"
 
 #define YYSTYPE_IS_DECLARED
@@ -600,7 +641,7 @@ parse_config(const char *filename, struc
 	if (stream == NULL) {
 		if (errno == ENOENT)
 			return (0);
-		warn("%s", filename);
+		fprintf(stderr, "%s: %s\n", filename, strerror(errno));
 		return (-1);
 	}
 	file = pushfile(filename, stream);
