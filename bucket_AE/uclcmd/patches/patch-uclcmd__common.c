--- uclcmd_common.c.orig	2021-12-06 19:25:25 UTC
+++ uclcmd_common.c
@@ -30,6 +30,35 @@
 
 #include "uclcmd.h"
 
+#ifdef __linux__
+#include <bsd/stdio.h>
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
+#endif
+
 /* 
  * This method is called with the arguments of asprintf() as parameter.
  * It handles error checking all instances of asprintf()
