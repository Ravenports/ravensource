--- video/scrcurses.c.orig	2024-06-06 15:45:53 UTC
+++ video/scrcurses.c
@@ -21,7 +21,7 @@
 
 #include <stdlib.h>
 #include <stdio.h>
-#include <curses.h>
+#include <ncurses/curses.h>
 #include <string.h>
 #include <unistd.h>
 
