--- joe/tty.c.orig	2018-01-10 16:28:34 UTC
+++ joe/tty.c
@@ -31,6 +31,10 @@
 #include <libutil.h>
 #endif
 
+#if defined(__NetBSD__)
+#include <util.h>
+#endif
+
 #endif
 
 #ifdef HAVE_LOGIN_TTY
