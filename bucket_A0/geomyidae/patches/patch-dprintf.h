--- /dev/null	2026-04-10 23:26:30 UTC
+++ dprintf.h
@@ -0,0 +1,16 @@
+#ifndef DPRINTF_COMPAT_H
+#define DPRINTF_COMPAT_H
+
+#include <stdarg.h>
+
+/**
+ * dprintf - Print formatted output to a file descriptor.
+ * @fd: The file descriptor to write to.
+ * @format: The format string.
+ * @...: Variable arguments for the format string.
+ * 
+ * Returns the number of characters printed, or -1 on error.
+ */
+int dprintf(int fd, const char *format, ...);
+
+#endif /* DPRINTF_COMPAT_H */
