--- src/corelib/thread/qfutex_p.h.orig	2024-11-14 11:02:40 UTC
+++ src/corelib/thread/qfutex_p.h
@@ -35,7 +35,7 @@ QT_END_NAMESPACE
 
 #if defined(Q_OS_DARWIN)
 #  include "qfutex_mac_p.h"
-#elif defined(Q_OS_FREEBSD)
+#elif defined(Q_OS_FREEBSD) && !defined(__DragonFly__)
 #  include "qfutex_freebsd_p.h"
 #elif defined(Q_OS_LINUX) && !defined(QT_LINUXBASE)
 // use Linux mutexes everywhere except for LSB builds
