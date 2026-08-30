Include sys/time.h for timeval.

--- src/bin/imlib2_view.c.orig	2026-08-28 05:14:53 UTC
+++ src/bin/imlib2_view.c
@@ -3,6 +3,7 @@
 
 #include <X11/Xlib.h>
 #include <X11/keysym.h>
+#include <sys/time.h>
 #include <poll.h>
 #include <stdio.h>
 #include <stdlib.h>
