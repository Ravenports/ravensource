--- src/term.c.orig	2019-03-17 22:19:36 UTC
+++ src/term.c
@@ -28,6 +28,10 @@
 #include <sys/select.h>
 #include <sys/time.h>
 
+#ifdef __sun__
+#include <sys/termios.h>
+#endif
+
 #define streq(a,b) (!strcmp(a,b))
 
 /* unit multipliers for working in microseconds */
