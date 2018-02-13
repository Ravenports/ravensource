--- va/va.c.orig	2018-02-12 06:32:11 UTC
+++ va/va.c
@@ -383,7 +383,7 @@ static VAStatus va_openDriver(VADisplay
         strncat( driver_path, DRIVER_EXTENSION, strlen(DRIVER_EXTENSION) );
         
         va_infoMessage(dpy, "Trying to open %s\n", driver_path);
-#ifndef ANDROID
+#ifdef RTLD_NODELETE
         handle = dlopen( driver_path, RTLD_NOW | RTLD_GLOBAL | RTLD_NODELETE );
 #else
         handle = dlopen( driver_path, RTLD_NOW| RTLD_GLOBAL);
