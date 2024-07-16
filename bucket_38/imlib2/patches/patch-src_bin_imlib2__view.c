Include sys/time.h for timeval.

--- src/bin/imlib2_view.c.orig	2024-07-06 09:58:30 UTC
+++ src/bin/imlib2_view.c
@@ -3,6 +3,7 @@
 
 #include <X11/Xlib.h>
 #include <X11/keysym.h>
+#include <sys/time.h>
 #include <poll.h>
 #include <stdio.h>
 #include <stdlib.h>
