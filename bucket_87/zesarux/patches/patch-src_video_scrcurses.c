--- video/scrcurses.c.orig	2026-06-09 16:37:08 UTC
+++ video/scrcurses.c
@@ -21,7 +21,7 @@
 
 #include <stdlib.h>
 #include <stdio.h>
-#include <curses.h>
+#include <ncurses/curses.h>
 #include <string.h>
 #include <unistd.h>
 
