--- src/term.c.orig	2025-03-17 14:48:34 UTC
+++ src/term.c
@@ -27,6 +27,10 @@
 #include <sys/select.h>
 #include <sys/time.h>
 
+#ifdef __sun__
+#include <sys/termios.h>
+#endif
+
 #define streq(a,b) (!strcmp(a,b))
 #define strneq(a,b,n) (strncmp(a,b,n)==0)
 
