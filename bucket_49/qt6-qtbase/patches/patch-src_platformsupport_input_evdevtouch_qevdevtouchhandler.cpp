--- src/platformsupport/input/evdevtouch/qevdevtouchhandler.cpp.orig	2022-11-16 07:54:24 UTC
+++ src/platformsupport/input/evdevtouch/qevdevtouchhandler.cpp
@@ -17,11 +17,7 @@
 
 #include <mutex>
 
-#ifdef Q_OS_FREEBSD
-#include <dev/evdev/input.h>
-#else
 #include <linux/input.h>
-#endif
 
 #ifndef input_event_sec
 #define input_event_sec time.tv_sec
