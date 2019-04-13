--- src/term.c.orig	2019-04-12 15:53:40 UTC
+++ src/term.c
@@ -33,6 +33,10 @@
 #include <sys/select.h>
 #include <sys/time.h>
 
+#ifdef __sun__
+#include <sys/termios.h>
+#endif
+
 #define streq(a,b) (!strcmp(a,b))
 
 /* unit multipliers for working in microseconds */
