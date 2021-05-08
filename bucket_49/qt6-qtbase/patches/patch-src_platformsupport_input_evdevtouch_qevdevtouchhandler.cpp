--- src/platformsupport/input/evdevtouch/qevdevtouchhandler.cpp.orig	2021-04-30 09:31:33 UTC
+++ src/platformsupport/input/evdevtouch/qevdevtouchhandler.cpp
@@ -53,11 +53,7 @@
 
 #include <mutex>
 
-#ifdef Q_OS_FREEBSD
-#include <dev/evdev/input.h>
-#else
 #include <linux/input.h>
-#endif
 
 #ifndef input_event_sec
 #define input_event_sec time.tv_sec
