--- src/ncurses_compat.c.orig	2020-02-02 23:34:34 UTC
+++ src/ncurses_compat.c
@@ -39,7 +39,6 @@
 /*
  * Provide compatibility with older versions of ncurses.
  */
-#include <ncurses_cfg.h>
 
 #if HAVE_INTTYPES_H
 # include <inttypes.h>
@@ -49,7 +48,7 @@
 # endif
 #endif
 
-#include <curses.h>
+#include <ncurses/curses.h>
 
 #if defined(NCURSES_VERSION_PATCH)
 
