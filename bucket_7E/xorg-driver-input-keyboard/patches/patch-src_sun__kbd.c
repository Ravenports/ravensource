--- src/sun_kbd.c.orig	2024-11-14 20:26:00 UTC
+++ src/sun_kbd.c
@@ -61,7 +61,6 @@
 #include <sys/kbd.h>
 #include <sys/kbio.h>
 #include <sys/note.h>	/* needed before including older versions of hid.h */
-#include <sys/usb/clients/hid/hid.h>
 
 static int KbdOn(InputInfoPtr pInfo, int what);
 static Bool OpenKeyboard(InputInfoPtr pInfo);
