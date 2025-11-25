--- test/simple-xinit.c.orig	2025-10-28 17:14:33 UTC
+++ test/simple-xinit.c
@@ -34,6 +34,47 @@
 #include <sys/wait.h>
 #include <unistd.h>
 
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
 static void
 kill_server(int server_pid)
 {
