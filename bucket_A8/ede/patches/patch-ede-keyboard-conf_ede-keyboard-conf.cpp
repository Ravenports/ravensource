--- ede-keyboard-conf/ede-keyboard-conf.cpp.orig	2025-10-21 17:20:38.894523000 +0200
+++ ede-keyboard-conf/ede-keyboard-conf.cpp	2025-10-21 17:21:01.203558000 +0200
@@ -21,6 +21,7 @@
 #ifdef HAVE_XKBRULES
 #include <stdio.h>
 #include <string.h>
+#include <stdlib.h>
 #include <FL/Fl.H>
 #include <FL/x.H>
 #include <FL/Fl_Button.H>
