--- lib/irrlichtmt/source/Irrlicht/CIrrDeviceLinux.cpp.orig	2023-10-27 15:48:29 UTC
+++ lib/irrlichtmt/source/Irrlicht/CIrrDeviceLinux.cpp
@@ -8,7 +8,9 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <sys/types.h>
 #include <sys/utsname.h>
+#include <unistd.h>
 #include <time.h>
 #include <locale.h>
 #include "IEventReceiver.h"
@@ -751,7 +753,7 @@ EKEY_CODE CIrrDeviceLinux::getKeyCode(XE
 	}
 	if (keyCode == 0)
 	{
-		keyCode = KEY_UNKNOWN;
+		keyCode = (EKEY_CODE)KEY_UNKNOWN;
 		if ( !mp.X11Key )
 		{
 			os::Printer::log("No such X11Key, event keycode", core::stringc(event.xkey.keycode).c_str(), ELL_INFORMATION);
