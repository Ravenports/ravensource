--- csl/fox/src/FXGUISignal.cpp.orig	2015-12-14 20:30:04 UTC
+++ csl/fox/src/FXGUISignal.cpp
@@ -43,6 +43,9 @@
 #else
 #include <process.h>
 #endif
+#if defined(__sun)
+#include <sys/filio.h>		/* for FIONREAD */
+#endif
 #include "FXGUISignal.h"
 
 /*
