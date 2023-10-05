--- sal/osl/unx/file_volume.cxx.orig	2023-09-22 19:07:01 UTC
+++ sal/osl/unx/file_volume.cxx
@@ -46,6 +46,10 @@
 #define FREEBSD 1
 #endif
 
+#if defined(__MidnightBSD__)
+#define FREEBSD 1
+#endif
+
 #if defined(__sun)
 
 #include <sys/mnttab.h>
