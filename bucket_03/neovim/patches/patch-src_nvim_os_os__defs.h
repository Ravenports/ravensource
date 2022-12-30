--- src/nvim/os/os_defs.h.orig	2022-12-29 16:12:10 UTC
+++ src/nvim/os/os_defs.h
@@ -17,6 +17,10 @@
 # define NAME_MAX _XOPEN_NAME_MAX
 #endif
 
+#ifdef __sun__
+#define NAME_MAX	255
+#endif
+
 #define BASENAMELEN (NAME_MAX - 5)
 
 // Use the system path length if it makes sense.
