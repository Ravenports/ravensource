--- src/term.c.orig	2020-01-27 00:37:11 UTC
+++ src/term.c
@@ -27,6 +27,10 @@
 #include <sys/select.h>
 #include <sys/time.h>
 
+#ifdef __sun__
+#include <sys/termios.h>
+#endif
+
 #define streq(a,b) (!strcmp(a,b))
 
 /* unit multipliers for working in microseconds */
