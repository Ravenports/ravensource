Supports ncurses 6.5 changes

--- src/aacurses.c.orig	2001-04-26 14:37:31 UTC
+++ src/aacurses.c
@@ -71,8 +71,7 @@ static void curses_getsize(aa_context *
 {
     if (__resized_curses)
 	curses_uninit(c), curses_init(&c->params, NULL,&c->driverparams, NULL), __resized_curses = 0;
-    *width = stdscr->_maxx + 1;
-    *height = stdscr->_maxy + 1;
+    getmaxyx(stdscr, *width, *height);
 #ifdef GPM_MOUSEDRIVER
     gpm_mx = *width;
     gpm_my = *height;
