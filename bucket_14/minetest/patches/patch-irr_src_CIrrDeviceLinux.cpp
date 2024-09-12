--- irr/src/CIrrDeviceLinux.cpp.orig	2024-08-11 15:54:55 UTC
+++ irr/src/CIrrDeviceLinux.cpp
@@ -45,9 +45,12 @@
 #include <X11/Xcursor/Xcursor.h>
 #endif
 
+#if defined(_IRR_COMPILE_WITH_X11_) || defined(_IRR_COMPILE_WITH_JOYSTICK_EVENTS_)
+#include <unistd.h>
+#endif
+
 #if defined _IRR_COMPILE_WITH_JOYSTICK_EVENTS_
 #include <fcntl.h>
-#include <unistd.h>
 
 #ifdef __FreeBSD__
 #include <sys/joystick.h>
@@ -709,7 +712,7 @@ EKEY_CODE CIrrDeviceLinux::getKeyCode(XE
 		keyCode = (EKEY_CODE)KeyMap[idx].Win32Key;
 	}
 	if (keyCode == 0) {
-		keyCode = KEY_UNKNOWN;
+		keyCode = (EKEY_CODE)KEY_UNKNOWN;
 		if (!mp.X11Key) {
 			os::Printer::log("No such X11Key, event keycode", core::stringc(event.xkey.keycode).c_str(), ELL_INFORMATION);
 		} else if (idx == -1) {
