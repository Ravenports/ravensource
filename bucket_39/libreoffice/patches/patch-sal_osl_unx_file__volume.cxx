--- sal/osl/unx/file_volume.cxx.orig	2026-04-24 19:21:51 UTC
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
