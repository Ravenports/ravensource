--- src/platformsupport/input/evdevkeyboard/qevdevkeyboardhandler.cpp.orig	2020-10-27 08:02:11 UTC
+++ src/platformsupport/input/evdevkeyboard/qevdevkeyboardhandler.cpp
@@ -52,11 +52,7 @@
 #include <QtGui/private/qguiapplication_p.h>
 #include <QtGui/private/qinputdevicemanager_p.h>
 
-#ifdef Q_OS_FREEBSD
-#include <dev/evdev/input.h>
-#else
 #include <linux/input.h>
-#endif
 
 #ifndef input_event_sec
 #define input_event_sec time.tv_sec
