--- src/c_varargs_to_ada.h.orig	2015-08-06 23:08:47 UTC
+++ src/c_varargs_to_ada.h
@@ -34,12 +34,12 @@
 #ifdef HAVE_CONFIG_H
 #include <ncurses_cfg.h>
 #else
-#include <ncurses.h>
+#include <ncurses/ncurses.h>
 #endif
 
 #include <stdlib.h>
 
-#include <form.h>
+#include <ncurses/form.h>
 
 extern int set_field_type_alnum(FIELD * /* field */ ,
 				int /* minimum_width */ );
