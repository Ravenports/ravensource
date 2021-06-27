--- src/platformsupport/input/evdevtouch/qevdevtouchhandler.cpp.orig	2021-06-01 12:03:51 UTC
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
