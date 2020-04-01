--- src/platformsupport/input/evdevtouch/qevdevtouchhandler.cpp.orig	2020-03-27 09:49:31 UTC
+++ src/platformsupport/input/evdevtouch/qevdevtouchhandler.cpp
@@ -52,11 +52,7 @@
 
 #include <mutex>
 
-#ifdef Q_OS_FREEBSD
-#include <dev/evdev/input.h>
-#else
 #include <linux/input.h>
-#endif
 
 #include <math.h>
 
