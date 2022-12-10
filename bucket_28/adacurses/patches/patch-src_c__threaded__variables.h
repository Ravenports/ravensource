--- src/c_threaded_variables.h.orig	2020-02-02 23:34:34 UTC
+++ src/c_threaded_variables.h
@@ -32,7 +32,6 @@
 #ifndef __C_THREADED_VARIABLES_H
 #define __C_THREADED_VARIABLES_H
 
-#include <ncurses_cfg.h>
 
 #if HAVE_INTTYPES_H
 # include <inttypes.h>
@@ -42,7 +41,7 @@
 # endif
 #endif
 
-#include <curses.h>
+#include <ncurses/curses.h>
 
 extern WINDOW *stdscr_as_function(void);
 extern WINDOW *curscr_as_function(void);
