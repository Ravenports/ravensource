--- src/platformsupport/input/evdevtablet/qevdevtablethandler.cpp.orig	2024-10-01 10:46:30 UTC
+++ src/platformsupport/input/evdevtablet/qevdevtablethandler.cpp
@@ -10,22 +10,7 @@
 #include <QLoggingCategory>
 #include <QtCore/private/qcore_unix_p.h>
 #include <qpa/qwindowsysteminterface.h>
-#ifdef Q_OS_FREEBSD
-#include <dev/evdev/input.h>
-#elif defined(Q_OS_VXWORKS)
-#include <qpa/qplatformscreen.h>
-#include <evdevLib.h>
-#define SYN_REPORT      0
-#define EV_SYN          EV_DEV_SYN
-#define EV_KEY          EV_DEV_KEY
-#define EV_ABS          EV_DEV_ABS
-#define ABS_X           EV_DEV_PTR_ABS_X
-#define ABS_Y           EV_DEV_PTR_ABS_Y
-#define BTN_TOUCH       EV_DEV_PTR_BTN_TOUCH
-typedef EV_DEV_EVENT input_event;
-#else
 #include <linux/input.h>
-#endif
 
 QT_BEGIN_NAMESPACE
 
