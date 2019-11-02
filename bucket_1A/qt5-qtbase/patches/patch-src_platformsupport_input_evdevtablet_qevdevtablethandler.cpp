--- src/platformsupport/input/evdevtablet/qevdevtablethandler.cpp.orig	2019-10-25 07:16:48 UTC
+++ src/platformsupport/input/evdevtablet/qevdevtablethandler.cpp
@@ -45,11 +45,7 @@
 #include <QLoggingCategory>
 #include <QtCore/private/qcore_unix_p.h>
 #include <qpa/qwindowsysteminterface.h>
-#ifdef Q_OS_FREEBSD
-#include <dev/evdev/input.h>
-#else
 #include <linux/input.h>
-#endif
 
 QT_BEGIN_NAMESPACE
 
