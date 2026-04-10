--- /dev/null	2026-04-10 23:26:30 UTC
+++ dprintf.c
@@ -0,0 +1,25 @@
+#include "dprintf.h"
+#include <stdio.h>
+#include <stdarg.h>
+#include <unistd.h>
+
+int dprintf(int fd, const char *format, ...) {
+    va_list args;
+    int result;
+
+    // Use fdopen to create a temporary stream. 
+    // "a" (append) is used to avoid truncating existing data in the descriptor.
+    FILE *fp = fdopen(dup(fd), "a");
+    if (!fp) {
+        return -1;
+    }
+
+    va_start(args, format);
+    result = vfprintf(fp, format, args);
+    va_end(args);
+
+    // Closing the stream created by fdopen also flushes it.
+    fclose(fp);
+    
+    return result;
+}
