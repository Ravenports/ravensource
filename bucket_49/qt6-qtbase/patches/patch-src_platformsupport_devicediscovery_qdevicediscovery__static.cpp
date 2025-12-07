--- src/platformsupport/devicediscovery/qdevicediscovery_static.cpp.orig	2025-11-12 10:17:57 UTC
+++ src/platformsupport/devicediscovery/qdevicediscovery_static.cpp
@@ -11,11 +11,7 @@
 #include <QLoggingCategory>
 #include <QtCore/private/qcore_unix_p.h>
 
-#ifdef Q_OS_FREEBSD
-#include <dev/evdev/input.h>
-#else
 #include <linux/input.h>
-#endif
 #include <fcntl.h>
 
 /* android (and perhaps some other linux-derived stuff) don't define everything
