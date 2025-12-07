--- src/corelib/thread/qfutex_p.h.orig	2025-11-12 10:17:57 UTC
+++ src/corelib/thread/qfutex_p.h
@@ -36,7 +36,7 @@ QT_END_NAMESPACE
 
 #if defined(Q_OS_DARWIN)
 #  include "qfutex_mac_p.h"
-#elif defined(Q_OS_FREEBSD)
+#elif defined(Q_OS_FREEBSD) && !defined(__DragonFly__)
 #  include "qfutex_freebsd_p.h"
 #elif defined(Q_OS_LINUX) && !defined(QT_LINUXBASE)
 // use Linux mutexes everywhere except for LSB builds
