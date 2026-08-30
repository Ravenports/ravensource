--- src/nvim/os/os_defs.h.orig	2026-08-23 16:59:44 UTC
+++ src/nvim/os/os_defs.h
@@ -30,6 +30,10 @@
 # define NAME_MAX _XOPEN_NAME_MAX
 #endif
 
+#ifdef __sun__
+#define NAME_MAX	255
+#endif
+
 #define BASENAMELEN (NAME_MAX - 5)
 
 // Use the system path length if it makes sense.
