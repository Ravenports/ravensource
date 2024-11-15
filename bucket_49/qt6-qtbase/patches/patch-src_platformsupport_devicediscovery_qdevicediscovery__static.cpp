--- src/platformsupport/devicediscovery/qdevicediscovery_static.cpp.orig	2024-10-01 10:46:30 UTC
+++ src/platformsupport/devicediscovery/qdevicediscovery_static.cpp
@@ -11,14 +11,7 @@
 #include <QLoggingCategory>
 #include <QtCore/private/qcore_unix_p.h>
 
-#ifdef Q_OS_FREEBSD
-#include <dev/evdev/input.h>
-#elif defined(Q_OS_VXWORKS)
-#include <evdevLib.h>
-#define ABS_X           EV_DEV_PTR_ABS_X
-#else
 #include <linux/input.h>
-#endif
 #include <fcntl.h>
 
 /* android (and perhaps some other linux-derived stuff) don't define everything
