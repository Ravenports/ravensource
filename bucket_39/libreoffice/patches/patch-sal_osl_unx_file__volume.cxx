--- sal/osl/unx/file_volume.cxx.orig	2026-01-27 21:11:38 UTC
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
