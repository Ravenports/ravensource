--- tools-for-build/grovel-headers.c.orig	2019-10-26 11:03:42 UTC
+++ tools-for-build/grovel-headers.c
@@ -43,7 +43,11 @@
   #include <termios.h>
 #else
 # ifndef LISP_FEATURE_HAIKU
+#  ifdef __DragonFly__
+#  include <termios.h>
+#  else
 #  include <sys/termios.h>
+#  endif
 # endif
   #include <langinfo.h>
 #endif
