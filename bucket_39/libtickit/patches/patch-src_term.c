--- src/term.c.orig	2018-01-05 14:57:48 UTC
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
