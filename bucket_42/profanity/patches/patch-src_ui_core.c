--- src/ui/core.c.orig	2026-03-26 11:17:31 UTC
+++ src/ui/core.c
@@ -29,6 +29,10 @@
 #include <curses.h>
 #endif
 
+#if defined __sun
+#include <sys/termios.h>
+#endif
+
 #include "log.h"
 #include "common.h"
 #include "command/cmd_defs.h"
