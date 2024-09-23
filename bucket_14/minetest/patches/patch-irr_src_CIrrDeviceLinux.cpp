--- irr/src/CIrrDeviceLinux.cpp.orig	2024-09-13 16:54:36 UTC
+++ irr/src/CIrrDeviceLinux.cpp
@@ -712,7 +712,7 @@ EKEY_CODE CIrrDeviceLinux::getKeyCode(XE
 		keyCode = (EKEY_CODE)KeyMap[idx].Win32Key;
 	}
 	if (keyCode == 0) {
-		keyCode = KEY_UNKNOWN;
+		keyCode = (EKEY_CODE)KEY_UNKNOWN;
 		if (!mp.X11Key) {
 			os::Printer::log("No such X11Key, event keycode", core::stringc(event.xkey.keycode).c_str(), ELL_INFORMATION);
 		} else if (idx == -1) {
