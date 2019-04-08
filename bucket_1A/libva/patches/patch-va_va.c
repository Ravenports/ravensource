--- va/va.c.orig	2019-04-07 17:44:47 UTC
+++ va/va.c
@@ -393,7 +393,7 @@ static VAStatus va_openDriver(VADisplay
         }
 
         va_infoMessage(dpy, "Trying to open %s\n", driver_path);
-#ifndef ANDROID
+#ifdef RTLD_NODELETE
         handle = dlopen( driver_path, RTLD_NOW | RTLD_GLOBAL | RTLD_NODELETE );
 #else
         handle = dlopen( driver_path, RTLD_NOW| RTLD_GLOBAL);
