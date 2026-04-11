--- utils/pathut.cpp.orig	2026-02-12 12:31:20 UTC
+++ utils/pathut.cpp
@@ -63,6 +63,8 @@
 #include <stdio.h>
 #include <vector>
 #include <fcntl.h>
+#include <limits.h>
+#include <stdlib.h>
 
 // Listing directories: we include the normal dirent.h on Unix-derived
 // systems, and on MinGW, where it comes with a supplemental wide char
@@ -74,6 +76,11 @@
 #include <dirent.h>
 #endif // _MSC_VER
 
+#if defined(__sun)
+#undef rewinddir
+#undef seekdir
+#undef telldir
+#endif
 
 #ifdef _WIN32
 
@@ -541,10 +548,20 @@ std::string path_which(const std::string
 std::string path_thisexecdir()
 {
     char pathbuf[PATH_MAX];
+#if defined(__sun)
+    const char* exec = getexecname();
+    if (exec) {
+        /* getexecname can return relative paths; use realpath to resolve it */
+        if (realpath(exec, pathbuf)) {
+            return path_getfather(std::string(pathbuf));
+        }
+    }
+#else
     /* Works on Linux */
     if (ssize_t buff_len = readlink("/proc/self/exe", pathbuf, PATH_MAX - 1); buff_len != -1) {
         return path_getfather(std::string(pathbuf, buff_len));
     }
+#endif
 
     /* If argv0 is null we're doomed: execve("foobar", nullptr, nullptr) */
     if (argv0.empty()) {
