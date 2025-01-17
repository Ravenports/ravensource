--- video/scrcurses.c.orig	2025-01-16 17:27:12 UTC
+++ video/scrcurses.c
@@ -21,7 +21,7 @@
 
 #include <stdlib.h>
 #include <stdio.h>
-#include <curses.h>
+#include <ncurses/curses.h>
 #include <string.h>
 #include <unistd.h>
 
