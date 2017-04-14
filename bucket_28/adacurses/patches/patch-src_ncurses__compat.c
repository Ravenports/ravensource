--- src/ncurses_compat.c.orig	2015-08-06 23:09:10 UTC
+++ src/ncurses_compat.c
@@ -38,7 +38,6 @@
 /*
  * Provide compatibility with older versions of ncurses.
  */
-#include <ncurses_cfg.h>
 
 #if HAVE_INTTYPES_H
 # include <inttypes.h>
@@ -48,7 +47,7 @@
 # endif
 #endif
 
-#include <curses.h>
+#include <ncurses/curses.h>
 
 #if defined(NCURSES_VERSION_PATCH)
 
