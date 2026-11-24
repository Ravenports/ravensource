--- tty.c.orig	2026-07-19 15:45:19 UTC
+++ tty.c
@@ -35,6 +35,9 @@
 #include <stdio.h>
 #include <term.h>
 #include <unistd.h>
+#if defined(__sun__)
+#include <sys/termios.h>
+#endif
 
 #include "def.h"
 
