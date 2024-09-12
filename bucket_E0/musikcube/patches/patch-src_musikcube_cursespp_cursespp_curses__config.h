--- src/musikcube/cursespp/cursespp/curses_config.h.orig	2024-07-14 19:37:30 UTC
+++ src/musikcube/cursespp/cursespp/curses_config.h
@@ -43,12 +43,9 @@
 #if defined(WIN32) || defined(NO_NCURSESW) && !defined(__DragonFly__)
     #include <curses.h>
     #include <panel.h>
-#elif defined(__DragonFly__)
+#else
     #include <ncurses/curses.h>
     #include <ncurses/panel.h>
-#else
-    #include <ncursesw/curses.h>
-    #include <ncursesw/panel.h>
 #endif
 
 #include <stdarg.h>
