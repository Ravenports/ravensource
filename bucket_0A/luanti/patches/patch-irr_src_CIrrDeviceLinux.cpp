--- irr/src/CIrrDeviceLinux.cpp.orig	2025-08-01 12:22:14 UTC
+++ irr/src/CIrrDeviceLinux.cpp
@@ -8,7 +8,9 @@
 
 #include <cstdio>
 #include <cstdlib>
+#include <sys/types.h>
 #include <sys/utsname.h>
+#include <unistd.h>
 #include <ctime>
 #include <clocale>
 #include "IEventReceiver.h"
@@ -673,7 +675,7 @@ EKEY_CODE CIrrDeviceLinux::getKeyCode(XE
 		keyCode = (EKEY_CODE)KeyMap[idx].Win32Key;
 	}
 	if (keyCode == 0) {
-		keyCode = KEY_UNKNOWN;
+		keyCode = (EKEY_CODE)KEY_UNKNOWN;
 		if (!mp.X11Key) {
 			os::Printer::log("No such X11Key, event keycode", core::stringc(event.xkey.keycode).c_str(), ELL_INFORMATION);
 		} else if (idx == -1) {
