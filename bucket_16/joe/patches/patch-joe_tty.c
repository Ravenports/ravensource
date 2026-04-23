--- joe/tty.c.orig	2026-04-01 01:06:07 UTC
+++ joe/tty.c
@@ -36,6 +36,10 @@
 #include <libutil.h>
 #endif
 
+#if defined(__NetBSD__)
+#include <util.h>
+#endif
+
 #endif
 
 #ifdef HAVE_LOGIN_TTY
