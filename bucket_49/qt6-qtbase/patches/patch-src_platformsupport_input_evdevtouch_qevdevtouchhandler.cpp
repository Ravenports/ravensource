--- src/platformsupport/input/evdevtouch/qevdevtouchhandler.cpp.orig	2025-08-11 04:54:51 UTC
+++ src/platformsupport/input/evdevtouch/qevdevtouchhandler.cpp
@@ -19,11 +19,7 @@
 
 #include <mutex>
 
-#ifdef Q_OS_FREEBSD
-#include <dev/evdev/input.h>
-#else
 #include <linux/input.h>
-#endif
 
 #ifndef input_event_sec
 #define input_event_sec time.tv_sec
