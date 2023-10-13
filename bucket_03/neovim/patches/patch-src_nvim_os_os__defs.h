--- src/nvim/os/os_defs.h.orig	2023-10-09 20:38:17 UTC
+++ src/nvim/os/os_defs.h
@@ -23,6 +23,10 @@
 # define NAME_MAX _XOPEN_NAME_MAX
 #endif
 
+#ifdef __sun__
+#define NAME_MAX	255
+#endif
+
 #define BASENAMELEN (NAME_MAX - 5)
 
 // Use the system path length if it makes sense.
