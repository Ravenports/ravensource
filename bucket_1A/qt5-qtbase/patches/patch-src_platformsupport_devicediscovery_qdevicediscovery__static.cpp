--- src/platformsupport/devicediscovery/qdevicediscovery_static.cpp.orig	2023-04-24 13:43:14 UTC
+++ src/platformsupport/devicediscovery/qdevicediscovery_static.cpp
@@ -47,11 +47,7 @@
 #include <QLoggingCategory>
 #include <QtCore/private/qcore_unix_p.h>
 
-#ifdef Q_OS_FREEBSD
-#include <dev/evdev/input.h>
-#else
 #include <linux/input.h>
-#endif
 #include <fcntl.h>
 
 /* android (and perhaps some other linux-derived stuff) don't define everything
