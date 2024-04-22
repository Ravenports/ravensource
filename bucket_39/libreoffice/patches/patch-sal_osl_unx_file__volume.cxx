--- sal/osl/unx/file_volume.cxx.orig	2024-03-22 19:34:51 UTC
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
