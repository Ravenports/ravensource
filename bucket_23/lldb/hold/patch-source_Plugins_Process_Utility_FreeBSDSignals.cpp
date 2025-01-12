--- source/Plugins/Process/Utility/FreeBSDSignals.cpp.orig	2024-12-17 11:04:04 UTC
+++ source/Plugins/Process/Utility/FreeBSDSignals.cpp
@@ -8,7 +8,7 @@
 
 #include "FreeBSDSignals.h"
 
-#ifdef __FreeBSD__
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 #include <csignal>
 
 #ifndef FPE_FLTIDO
