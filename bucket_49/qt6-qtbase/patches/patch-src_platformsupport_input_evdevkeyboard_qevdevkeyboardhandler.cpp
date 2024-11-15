--- src/platformsupport/input/evdevkeyboard/qevdevkeyboardhandler.cpp.orig	2024-10-01 10:46:30 UTC
+++ src/platformsupport/input/evdevkeyboard/qevdevkeyboardhandler.cpp
@@ -17,13 +17,7 @@
 #include <QtGui/private/qguiapplication_p.h>
 #include <QtGui/private/qinputdevicemanager_p.h>
 
-#ifdef Q_OS_FREEBSD
-#include <dev/evdev/input.h>
-#elif defined(Q_OS_VXWORKS)
-#include <evdevLib.h>
-#else
 #include <linux/input.h>
-#endif
 
 #ifndef input_event_sec
 #define input_event_sec time.tv_sec
