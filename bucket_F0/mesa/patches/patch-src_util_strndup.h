--- src/util/strndup.h.orig	2025-06-18 17:45:40 UTC
+++ src/util/strndup.h
@@ -24,7 +24,7 @@
 #ifndef STRNDUP_H
 #define STRNDUP_H
 
-#if defined(_WIN32)
+#if defined(_WIN32) || defined(__sun)
 
 #include <stdlib.h> // size_t
 #include <string.h>
@@ -34,6 +34,7 @@ extern "C" {
 #endif
 
 static inline char *
+#if defined(_WIN32)
 strndup(const char *str, size_t max)
 {
    size_t n;
@@ -50,6 +51,22 @@ strndup(const char *str, size_t max)
    memcpy(ptr, str, n);
    return ptr;
 }
+#else  // version without strnlen
+strndup(const char *str, size_t n)
+{
+    size_t len;
+    char *copy;
+
+    len = strlen(str);
+    if (len <= n)
+        return (strdup(str));
+    if ((copy = (char *)malloc(len + 1)) == NULL)
+        return (NULL);
+    memcpy(copy, str, len);
+    copy[len] = '\0';
+    return (copy);
+}
+#endif
 
 #ifdef __cplusplus
 }
