--- src/platformsupport/input/evdevkeyboard/qevdevkeyboard_defaultmap_p.h.orig	2025-11-12 10:17:57 UTC
+++ src/platformsupport/input/evdevkeyboard/qevdevkeyboard_defaultmap_p.h
@@ -19,11 +19,7 @@
 #include <QtInputSupport/private/qkeyboardmap_p.h>
 
 #include "private/qglobal_p.h"
-#ifdef Q_OS_FREEBSD
-#include <dev/evdev/input.h>
-#else
 #include "linux/input.h"
-#endif
 
 // no QT_BEGIN_NAMESPACE, since we include it internally...
 
