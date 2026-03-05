--- core/src/executable_path.c.orig	2025-11-28 12:36:47 UTC
+++ core/src/executable_path.c
@@ -59,11 +59,63 @@ c_executable_path (char *buffer, int siz
     return readlink("/proc/self/exe", buffer, (size_t) size);
 }
 
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
+#include <stddef.h>
+#include <sys/types.h>
+#include <sys/sysctl.h>
+int
+c_executable_path (char *buffer, int size)
+{
+    int mib[4];
+    size_t len;
+
+    mib[0] = CTL_KERN;
+    mib[1] = KERN_PROC;
+    mib[2] = KERN_PROC_PATHNAME;
+    mib[3] = -1; // Targets the current process
+
+    if (sysctl(mib, 4, NULL, &len, NULL, 0) == -1)   { return 0; }
+    if (size < len)                                  { return 0; }
+    if (sysctl(mib, 4, buffer, &len, NULL, 0) == -1) { return 0; }
+    return len;
+}
+
+#elif defined(__NetBSD__)
+#include <sys/types.h>
+#include <unistd.h>
+int
+c_executable_path (char *buffer, int size)
+{
+    ssize_t len;
+    len = readlink("/proc/curproc/exe", buffer, (size_t) size - 1);
+    if (len > 0) {
+        buffer[len] = '\0';
+        return (int)len;
+    }
+    return 0;
+}
+
+#elif defined(__sun__)
+#include <unistd.h>
+#include <sys/types.h>
+int
+c_executable_path(char *buffer, int size)
+{
+    ssize_t len = readlink("/proc/self/path/a.out", buffer, (size_t)size - 1);
+
+    if (len > 0) {
+        buffer[len] = '\0'; // Manually null-terminate for C-string compatibility
+        return (int)len;    // Return length on success
+    }
+    return 0;
+}
+
 #else
 /* Dummy implementation */
 int
 c_executable_path (char *buffer, int size)
 {
+#error Unsupported target platform.  Please implement c_executable_path() for this platform.
     return 0;
 }
 #endif
