--- src/nvim/os/os_defs.h.orig	2024-10-03 08:48:34 UTC
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
