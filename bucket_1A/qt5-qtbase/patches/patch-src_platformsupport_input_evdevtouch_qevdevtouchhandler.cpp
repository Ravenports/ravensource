--- src/platformsupport/input/evdevtouch/qevdevtouchhandler.cpp.orig	2025-06-05 14:07:26 UTC
+++ src/platformsupport/input/evdevtouch/qevdevtouchhandler.cpp
@@ -52,11 +52,7 @@
 
 #include <mutex>
 
-#ifdef Q_OS_FREEBSD
-#include <dev/evdev/input.h>
-#else
 #include <linux/input.h>
-#endif
 
 #ifndef input_event_sec
 #define input_event_sec time.tv_sec
