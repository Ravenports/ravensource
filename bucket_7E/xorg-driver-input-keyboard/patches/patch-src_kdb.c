--- src/kbd.c.orig	2022-07-10 23:28:06 UTC
+++ src/kbd.c
@@ -25,6 +25,7 @@
 
 #include "xf86.h"
 #include "atKeynames.h"
+#include "xf86Priv.h"
 #include "xf86Privstr.h"
 
 #include <X11/extensions/XI.h>
@@ -382,6 +383,14 @@ KbdProc(DeviceIntPtr device, int what)
     }
     pKbd->KbdOff(pInfo, what);
     device->public.on = FALSE;
+	/*
+	 * Close device file for keyboards which are not attached
+	 * to console, otherwise they can't be opened again after
+	 * relogin when using session manager like xdm.
+	 * X server will take care about console attached keyboards.
+	 */
+	if (pInfo->fd != xf86Info.consoleFd)
+		close(pInfo->fd);
     break;
 
   default:
