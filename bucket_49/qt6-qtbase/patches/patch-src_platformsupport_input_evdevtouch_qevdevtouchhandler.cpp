--- src/platformsupport/input/evdevtouch/qevdevtouchhandler.cpp.orig	2024-10-01 10:46:30 UTC
+++ src/platformsupport/input/evdevtouch/qevdevtouchhandler.cpp
@@ -19,27 +19,7 @@
 
 #include <mutex>
 
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
-#define ABS_MAX         0x3f
-#define ABS_MT_SLOT     EV_DEV_PTR_ABS_MT_SLOT //0x2F
-#define ABS_MT_POSITION_X   EV_DEV_PTR_ABS_MT_POSITION_X //0x35
-#define ABS_MT_POSITION_Y   EV_DEV_PTR_ABS_MT_POSITION_Y //0x36
-#define ABS_MT_TRACKING_ID  EV_DEV_PTR_ABS_MT_TRACKING_ID //0x39
-typedef EV_DEV_EVENT input_event;
-#else
 #include <linux/input.h>
-#endif
 
 #ifndef input_event_sec
 #define input_event_sec time.tv_sec
