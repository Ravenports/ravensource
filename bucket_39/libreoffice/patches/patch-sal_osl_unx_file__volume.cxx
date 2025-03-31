--- sal/osl/unx/file_volume.cxx.orig	2025-03-21 15:34:31 UTC
+++ sal/osl/unx/file_volume.cxx
@@ -42,6 +42,10 @@
 #define FREEBSD 1
 #endif
 
+#if defined(__MidnightBSD__)
+#define FREEBSD 1
+#endif
+
 #if defined(__sun)
 
 #include <sys/mnttab.h>
