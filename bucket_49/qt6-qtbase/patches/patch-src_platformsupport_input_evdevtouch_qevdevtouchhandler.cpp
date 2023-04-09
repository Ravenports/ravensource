--- src/platformsupport/input/evdevtouch/qevdevtouchhandler.cpp.orig	2023-03-14 08:29:43 UTC
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
