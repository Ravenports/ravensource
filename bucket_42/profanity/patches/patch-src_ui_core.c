--- src/ui/core.c.orig	2026-02-23 09:09:50 UTC
+++ src/ui/core.c
@@ -55,6 +55,10 @@
 #include <curses.h>
 #endif
 
+#if defined __sun
+#include <sys/termios.h>
+#endif
+
 #include "log.h"
 #include "common.h"
 #include "command/cmd_defs.h"
