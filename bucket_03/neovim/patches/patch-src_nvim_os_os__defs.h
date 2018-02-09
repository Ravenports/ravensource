--- src/nvim/os/os_defs.h.orig	2017-11-18 11:39:14 UTC
+++ src/nvim/os/os_defs.h
@@ -20,6 +20,10 @@ enum {
   OS_STDERR_FILENO = STDERR_FILENO,
 };
 
+#ifdef __sun__
+#define NAME_MAX	255
+#endif
+
 #define BASENAMELEN (NAME_MAX - 5)
 
 // Use the system path length if it makes sense.
