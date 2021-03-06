--- src/termsize.cpp.orig	2021-03-01 12:47:02 UTC
+++ src/termsize.cpp
@@ -8,7 +8,11 @@
 #include "wutil.h"
 
 #ifdef HAVE_WINSIZE
+# if defined(__FreeBSD__) || defined(__DragonFly__)
+#include <termios.h>
+# else
 #include <sys/termios.h>
+# endif
 #endif
 
 // A counter which is incremented every SIGWINCH, or when the tty is otherwise invalidated.
