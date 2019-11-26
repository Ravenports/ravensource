--- src/term.c.orig	2019-11-18 17:09:53 UTC
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
