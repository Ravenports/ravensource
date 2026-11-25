--- src/ui/core.c.orig	2026-11-19 09:24:26 UTC
+++ src/ui/core.c
@@ -25,6 +25,10 @@
 #include <curses.h>
 #endif
 
+#if defined __sun
+#include <sys/termios.h>
+#endif
+
 #include "log.h"
 #include "common.h"
 #include "command/cmd_defs.h"
