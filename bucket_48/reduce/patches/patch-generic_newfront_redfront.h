--- generic/newfront/redfront.h.orig	2021-03-16 10:41:22 UTC
+++ generic/newfront/redfront.h
@@ -81,6 +81,9 @@
 #include <wchar.h>
 #include <string.h>
 #include <signal.h>
+#if defined(__sun)
+typedef void (*sig_t)(int);
+#endif
 
 #ifdef NATIVE_WINDOWS
 
