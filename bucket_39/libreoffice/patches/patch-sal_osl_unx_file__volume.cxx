--- sal/osl/unx/file_volume.cxx.orig	2026-01-14 23:16:14 UTC
+++ sal/osl/unx/file_volume.cxx
@@ -43,6 +43,10 @@
 #define FREEBSD 1
 #endif
 
+#if defined(__MidnightBSD__)
+#define FREEBSD 1
+#endif
+
 #if defined(__sun)
 
 #include <sys/mnttab.h>
