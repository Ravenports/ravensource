--- tty.c.orig	2024-07-09 15:39:50 UTC
+++ tty.c
@@ -35,6 +35,9 @@
 #include <stdio.h>
 #include <term.h>
 #include <unistd.h>
+#if defined(__sun__)
+#include <sys/termios.h>
+#endif
 
 #include "def.h"
 
