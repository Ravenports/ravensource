--- src/c_threaded_variables.h.orig	2015-08-06 23:09:47 UTC
+++ src/c_threaded_variables.h
@@ -31,7 +31,6 @@
 #ifndef __C_THREADED_VARIABLES_H
 #define __C_THREADED_VARIABLES_H
 
-#include <ncurses_cfg.h>
 
 #if HAVE_INTTYPES_H
 # include <inttypes.h>
@@ -41,7 +40,7 @@
 # endif
 #endif
 
-#include <curses.h>
+#include <ncurses/curses.h>
 
 extern WINDOW *stdscr_as_function(void);
 extern WINDOW *curscr_as_function(void);
