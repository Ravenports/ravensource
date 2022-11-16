--- src/nvim/os/os_defs.h.orig	2022-11-14 09:12:05 UTC
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
