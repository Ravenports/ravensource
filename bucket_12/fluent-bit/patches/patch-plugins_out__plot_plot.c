--- plugins/out_plot/plot.c.orig	2026-02-19 03:26:01 UTC
+++ plugins/out_plot/plot.c
@@ -27,6 +27,8 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <fcntl.h>
+#include <stdarg.h>
+#include <unistd.h>
 
 struct flb_plot {
     const char *out_file;
@@ -34,6 +36,33 @@ struct flb_plot {
     struct flb_output_instance *ins;
 };
 
+#if defined(__sun__)
+static int dprintf(int fd, const char *format, ...) {
+    char buffer[1024];
+    va_list args;
+    int ret;
+
+    va_start(args, format);
+    // Format the string into our local buffer
+    ret = vsnprintf(buffer, sizeof(buffer), format, args);
+    va_end(args);
+
+    if (ret < 0) {
+        return -1;
+    }
+
+    // Handle potential truncation: vsnprintf returns the number of 
+    // characters that *would* have been written.
+    size_t len = (size_t)ret;
+    if (len >= sizeof(buffer)) {
+        len = sizeof(buffer) - 1;
+    }
+
+    // Write the formatted buffer to the file descriptor
+    return (int)write(fd, buffer, len);
+}
+#endif
+
 static int cb_plot_init(struct flb_output_instance *ins,
                         struct flb_config *config,
                         void *data)
