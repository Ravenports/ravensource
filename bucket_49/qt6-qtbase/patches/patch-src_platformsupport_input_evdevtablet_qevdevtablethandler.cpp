--- src/platformsupport/input/evdevtablet/qevdevtablethandler.cpp.orig	2021-02-11 10:23:05 UTC
+++ src/platformsupport/input/evdevtablet/qevdevtablethandler.cpp
@@ -46,11 +46,7 @@
 #include <QLoggingCategory>
 #include <QtCore/private/qcore_unix_p.h>
 #include <qpa/qwindowsysteminterface.h>
-#ifdef Q_OS_FREEBSD
-#include <dev/evdev/input.h>
-#else
 #include <linux/input.h>
-#endif
 
 QT_BEGIN_NAMESPACE
 
